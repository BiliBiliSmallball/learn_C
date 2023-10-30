# 该程序从exl表格中提取人名并合成一个TXT文档
import xlrd

def FOpen(path, wb):
    """
    本函数是创建了一个对象,并将该对象的行，列的具体数目
    从中返回一个列表后传到下个函数
    """
    data = xlrd.open_workbook(path)
    ws = data.sheet_by_name(wb)

    # 创建字典，方便导出
    total = {}

    # 读取行数
    hang = ws.nrows  # 行

    # 核心部分，读取文件并加入字典
    for each in range(3, hang - 1):
        result = ws.cell_value(each, 1)
        if result != "None":
            total[result] = ws.cell_value(each, 0)
    return total


def GetName(all_value, op_path):
    """
    本函数接受一个字典对象，从中遍历一个元素后输出一个值到文本中
    :param:all_value[传入的字典]，op_path[生成路径]
    :return:None
    """
    i = 0
    f = open(op_path + r"\students.txt", "w")
    for name in all_value:
        f.write(str(name))
        f.write("\n")
        # f.write(str(i) + "、" + str(all_value[id]) + "：" + str(id) + "\n")

    f.seek(0)
    print(f"文件已生成完成！，位于 {op_path} 中")
    return None


def main():
    # 演示用路径
    path = "E:\学校文件\班级\自动化22-2资料.xlsx"
    ws = "建档资料"
    save_address = r".\destination_folder"  # 文件存储地址

    # path = input("请输入文件路径")
    # ws = input("表格名")
    # save_address = input("请输入保存路径")

    return_ = FOpen(path, ws)
    GetName(return_, save_address)


if __name__ == '__main__':
    main()
    input("按下Enter键退出")
