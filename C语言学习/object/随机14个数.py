import random
#全局变量
base = []
tim=0


for i in range(100):
	base.append(i)

while tim <= 14:
	final = random.choice(base)
	print(final)
	tim += 1

#哈哈！你发现这个小彩蛋啦！这个文档不是C语言，而是一种更加精简的语言 ---- PYTHON
#欢迎你来学习！