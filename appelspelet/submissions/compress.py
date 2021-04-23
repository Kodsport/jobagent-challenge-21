x = input()

p = []
for pos, ch in enumerate(x):
    if ch == '1':
        p.append(str(pos))

print('[' + ','.join(p) + ']')
