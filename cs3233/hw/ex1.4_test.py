
print(f"{(s := (d:=__import__('datetime').date)(2010, 8, 9)).strftime('%a')}\n{(d.today()-s).days} day(s) ago")