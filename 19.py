day_of_week = [0, 1, 2, 3, 4, 5, 6]
month_reg = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
month_leap = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

year = 1900
current_day = 0
sunday_count = 0

assert sum(month_reg) == 365
assert sum(month_leap) == 366

while year < 2001:
    if year % 4 != 0:
        cal = month_reg
    else:
        if year % 400 == 0:
            cal = month_leap
        else:
            if year % 100 == 0:
                cal = month_reg
            else:
                cal = month_leap

    for days in cal:
        for i in range(days):
            current_day = day_of_week[(current_day + 1) % 7]
            if (i == 0) & (current_day == 0):
                if year > 1900:
                    sunday_count += 1

    year += 1

print(sunday_count)
