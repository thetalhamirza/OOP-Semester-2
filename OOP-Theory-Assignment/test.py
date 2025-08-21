months = ["January","February","March","April","May","June","July","August","September","October","November","December"]

while True:
    date = input("Date: ").strip()
    try:
        if "/" in date:
            month, day, year = date.split("/")
            # try:
            if month in months:
                raise ValueError
        elif "," in date:
            date = date.replace(",", "")
            month, day, year = date.split(" ")
        else:
            raise ValueError
    except ValueError:
        continue
    if month in months:
        month = months.index(month) + 1
    try:
        if int(month) > 12 or int(day) > 31:
            continue
        else:
            break
    except ValueError:
        continue

print(year + '-' + f"{int(month):02}" + '-' + f"{int(day):02}")