import sys, json
import time, datetime
#sys.stdin = open("INPUT")

def get_next_day(day):
    t = time.strptime(day, "%Y%m%d")
    new_date = datetime.date(t.tm_year, t.tm_mon, t.tm_mday) + datetime.timedelta(1)
    return new_date.strftime("%Y%m%d")

database_file_name = sys.argv[1]
with open(database_file_name,) as f:
    data_by_city = json.load(f)

data_by_date = {}
for city, city_data in data_by_city.items():
    for date, weather_data in city_data.items():
        if date not in data_by_date:
            data_by_date[date] = [{"city": city, "weather_data": weather_data}]
        else:
            data_by_date[date].append({"city": city, "weather_data": weather_data})

transform_command = {"temp": "temp", "humidity": "relhum", "pressure": "ap",
                     "maxtemp": "temp", "maxhumidity": "relhum", "maxpressure": "ap",
                     "warmestcity": -1 * float("inf"), "coldestcity": float("inf"),
                     "graphtemp": "temp", "graphpressure": "ap"}

for line in sys.stdin:
    try:
        line = line.strip().split()
        if len(line) == 0:
            continue

        command = line[0]
        args = {}
        for arg in line[1:]:
            arg = arg.split(":")
            args[arg[0]] = arg[1]

        if command in ["temp", "humidity", "pressure"]:
            ans = data_by_city[args["city"]][args["date"]][transform_command[command]]
            if transform_command[command] == "relhum":
                print(f'city:{args["city"]} date:{args["date"]} {command}:{round(100 * ans)}')
            else:
                print(f'city:{args["city"]} date:{args["date"]} {command}:{ans}')
            continue

        if command in ["maxtemp", "maxhumidity", "maxpressure"]:
            mx_so_far = -1 * float("inf")
            day = None
            for date, _data in data_by_date.items():
                for data in _data:
                    if args["city"] == data["city"]:
                        if args["startdate"] <= date <= args["enddate"]:
                            if data["weather_data"][transform_command[command]] > mx_so_far:
                                mx_so_far = data["weather_data"][transform_command[command]]
                                day = date
            
            if day == None: raise(ValueError)

            if transform_command[command] == "relhum":
                print(f'city:{args["city"]} date:{day} {command[3:]}:{round(100 * mx_so_far)}')
            else:
                print(f'city:{args["city"]} date:{day} {command[3:]}:{mx_so_far}')
            continue

        if command in ["warmestcity", "coldestcity"]:
            so_far = transform_command[command]
            city = None
            for data in data_by_date[args["date"]]:
                if command == "warmestcity":
                    if data["weather_data"]["temp"] > so_far:
                        so_far = data["weather_data"]["temp"]
                        city = data["city"]
                else:
                    if data["weather_data"]["temp"] < so_far:
                        so_far = data["weather_data"]["temp"]
                        city = data["city"]

            if city == None: raise(ValueError)

            print(f'city:{city} date:{args["date"]} temp:{so_far}')
            continue

        if command in ["graphtemp", "graphpressure"]:
            values = []
            day = args["startdate"]
            while day <= args["enddate"]:
                values.append(data_by_city[args["city"]][day][transform_command[command]])
                day = get_next_day(day)

            final_values = []
            if len(values) > 50:
                M = len(values)
                current = 0
                for i in range(M % 50):
                    avg = 0
                    for j in range((M // 50) + 1):
                        avg += values[current]
                        current += 1
                    final_values.append(avg / ((M // 50) + 1))
                
                while len(final_values) != 50:
                    avg = 0
                    for j in range(M // 50):
                        avg += values[current]
                        current += 1
                    final_values.append(avg / (M // 50))

            else:
                final_values = values

            min_temp = min(final_values)
            step = (max(final_values) - min(final_values)) / 19
            heights = []
            for value in final_values:
                heights.append(round((value - min_temp) / step) + 1)

            for i in range(20, 0, -1):
                for height in heights:
                    if height >= i:
                        print("#", end="")
                    else:
                        print(" ", end="")
                print()

            continue

        raise(NotImplementedError)

    except Exception as e:
        print("Invalid input")