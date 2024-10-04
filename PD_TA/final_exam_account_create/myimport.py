# use online gdb
# create team categories (the weekday) & affiliations (the group) first
# import accounts first
# then import team
# the data format: studentName studentID studentCategoryID studentAffiliationID

##################################################################
# edited by tuanghee
# accounts input format: studentID
# accounts output format: id, username, password, type, team_id
# teams input format: studentID dayofExam
# teams output format: id, name, members, group_ids
##################################################################

import secrets
from sys import stdin

def readData():
    stuInfo = []
    while True:
        try:
            x = input()
        except EOFError:
            break
        else:
            stuInfo.append(x)
    return stuInfo

def readTeamData():
    stuInfo = []
    for line in stdin:
        stuInfo.append(line.split())
    return stuInfo

def addQuo(str = ""):
    return '\"' + str + '\"'

def outFormat(former = "", later = "", sep = ','):
    return '\t' + addQuo(former) + ':' + addQuo(later) + sep

def makeTeam(stuInfo = [], startID = 5):
    flag = 0
    print('[', end = '')
    for stuID, stuGroup in stuInfo:
        if flag == 1:
            print(', {')
        else:
            print('{')
        print(outFormat('id', str(startID)))
        print(outFormat('name', stuID))
        print(outFormat('members', stuID))
        print('\t\"group_ids\": [\"' + stuGroup +'\"]')
        print('}', end = '')
        flag = 1
        startID += 1
    print(']')

def makeAccount(stuInfo = []):
    flag = 0
    passwordLen = 8
    teamId = 5
    print('[', end = '')
    for stuID in stuInfo:
        if flag == 1:
            print(', {')
        else:
            print('{')
        print(outFormat('id', stuID))
        print(outFormat('username', stuID))
        print(outFormat('password', secrets.token_urlsafe(passwordLen)[:8]))
        print(outFormat('type', 'team'))
        # print(outFormat('type', 'team', ''))
        print(outFormat('team_id', str(teamId), ''))
        print('}', end = '')
        flag = 1
        teamId += 1
    print(']')

stuInfo = readData()
# stuInfo = readTeamData()
# print(stuInfo)
makeAccount(stuInfo)
# makeTeam(stuInfo)