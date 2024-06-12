# use online gdb
# create team categories (the weekday) & affiliations (the group) first
# import accounts first
# then import team
# the data format: studentName studentID studentCategoryID studentAffiliationID

import secrets
from sys import stdin

def readData():
    stuInfo = []
    for line in stdin:
        stuInfo.append(line.split())
    stuInfo = stuInfo[1:]
    return stuInfo

def addQuo(str = ""):
    return '\"' + str + '\"'

def outFormat(former = "", later = "", sep = ','):
    return '\t' + addQuo(former) + ':' + addQuo(later) + sep

def makeTeam(stuInfo = [], startID = 4):
    flag = 0
    print('[', end = '')
    for stuName, stuID, stuQuiz, stuGroup in stuInfo:
        if flag == 1:
            print(', {')
        else:
            print('{')
        print(outFormat('id', startID))
        print('group_ids: [\"' + stuQuiz +'\"]')
        print(outFormat('name', stuID + ' ' + stuName))
        print(outFormat('organization_id', stuGroup, ""))
        print('}', end = '')
        flag = 1
        startID += 1
    print(']')

def makeAccount(stuInfo = []):
    flag = 0
    passwordLen = 8
    print('[', end = '')
    for stuName, stuID, stuQuiz, stuGroup in stuInfo:
        if flag == 1:
            print(', {')
        else:
            print('{')
        print(outFormat('id', stuID))
        print(outFormat('username', stuID))
        print(outFormat('password', secrets.token_urlsafe(passwordLen)[:8]))
        print(outFormat('type', 'team'))
        print(outFormat('team_id', stuID, ''))
        print('}', end = '')
        flag = 1
    print(']')

stuInfo = readData()
print(stuInfo)
makeTeam(stuInfo)