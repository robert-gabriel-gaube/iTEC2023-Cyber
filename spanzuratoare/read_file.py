import re


class Lines_2:
    def __init__(self, line1, line2, number):
        self.line1 = line1
        self.line2 = line2
        self.number = number


class Lines_3:
    def __init__(self, line1, line2, line3, num1, num2):
        self.line1 = line1
        self.line2 = line2
        self.line3 = line3
        self.num1 = num1
        self.num2 = num2

liners = []
liners_3 = []

with open("spanzuratoarea.py", "r") as f:
    lines = f.readlines()
    # start from 44 
    # end len(lines) - 1
    for i in range(len(lines)):
        lines[i] = lines[i][:-1]
        if lines[i] != '':
            lines[i] = lines[i][4:]

    for i in range(44, len(lines)):
        if lines[i] == '':
            if lines[i - 3] == '':
                result = re.search(r'\[(\d+)\]', lines[i - 2])
                liners.append(Lines_2(lines[i - 2], lines[i - 1][7:-1], int(result.group()[1:-1])))
            else:
                result1 = re.search(r'\[(\d+)\]', lines[i - 3])
                result2 = re.search(r'\[(\d+)\]', lines[i - 2])
                num1 = int(result1.group()[1:-1])
                num2 = int(result2.group()[1:-1])
                lines[i - 1] = lines[i - 1].replace(" ==", ") !=")
                liners_3.append(Lines_3(lines[i - 3], lines[i - 2], lines[i - 1][7:], num1, num2))

            
# with open("single_statement.txt", "w") as o:
#     liners.sort(key=lambda x: x.number)

#     o.write('0\n')
#     o.write('if('+ liners[0].line2 + ") {\ncontinue;\n}\n")

#     for i in range(1, len(liners)):
#         if liners[i].number != liners[i - 1].number:
#             o.write(str(liners[i].number) + '--------------------\n')
#             o.write('if (' +liners[i].line2 + '){\n\t\tcontinue;\n}\n')
#         else:
#             o.write('else if (' + liners[i].line2 + '){\n\t\tcontinue;\n}\n')

with open("binary_statement.txt", "w") as o:
    for line in liners_3:
        o.write(f"int x = {line.num1}, y = {line.num2};\n")
        o.write(f'vector<char>chars1 = get_chars({line.num1});\n')
        o.write(f'vector<char>chars2 = get_chars({line.num2});\n\n')

        o.write("set<char> stmp1;\nset<char> stmp2;\n")
        o.write("\tfor(char tmp1c : chars1) {\n")
        o.write("\t\tfor(char tmp2c : chars2) {\n")
        o.write("\t\t\tint tmp1 = static_cast<int>(tmp1c);\n")
        o.write("\t\t\tint tmp2 = static_cast<int>(tmp2c);\n")
        o.write("\t\t\tif((" + line.line3 + "){\n\t\t\t\tcontinue;\n\t\t\t}\n")
        o.write('\t\t\tstmp1.insert(tmp1c); stmp2.insert(tmp2c);\n')
        o.write("\t\t}\n")
        o.write("\t}\n")
        o.write("---------------------\n")