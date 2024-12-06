# use online gdb
# to import account by json, enable external id for domjudge
# in "Configuration settings -> External systems -> Data source" change "all local" to "configuration data external"
# create team categories (the weekday) & affiliations (the group) first
# import teams first
# then import accounts
# the input data format: studentName studentID studentCategoryID studentAffiliationID
# credit by: lune

import secrets
import sys

def readData():
    stuInfo = []
    for line in sys.stdin:
        stuInfo.append(line.strip())
    # stuInfo = stuInfo[1:]
    return stuInfo

def addQuo(str = ""):
    return '\"' + str + '\"'

def outFormat(former = "", later = "", sep = ','):
    return '\t' + addQuo(former) + ':' + addQuo(later) + sep

def makeTeam(stuInfo = [], startID = 4):
    flag = 0
    print('[', end = '')
    for stuID in stuInfo:
        if flag == 1:
            print(', {')
        else:
            print('{')
        print(outFormat('id', stuID))
        # print('\t\"group_ids\": [\"' + stuQuiz +'\"],')
        # print(outFormat('name', stuID + ' ' + stuName))
        print(outFormat('name', stuID))
        # print(outFormat('organization_id', stuGroup, ""))
        print('}', end = '')
        flag = 1
        startID += 1
    print(']')

def makeTeamTSV(stuInfo = []):
    print('File_Version\t2')
    for stuName, stuID, stuQuiz, stuGroup in stuInfo:
        print(stuID + '\t\t' + stuQuiz + '\t' + stuID + stuGroup + stuGroup + '\t\t')

def examMakeTeamTSV(stuInfo = []):
    print('File_Version\t2')
    for stuID in stuInfo:
        print(str(stuID) + '\t\t' + 'participants' + '\t' + str(stuID) + '\t\t\t\t')

def examEakeAccountTSV(stuInfo = []):
    print('accounts\t1')
    for stuID in stuInfo:
        print('team' + '\t' + str(stuID) + '\t' + str(stuID) + '\t' + secrets.token_urlsafe(10))

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
        # print(outFormat('password', secrets.token_urlsafe(passwordLen)[:8]))
        print(outFormat('password', stuID))
        print(outFormat('type', 'team'))
        print(outFormat('team_id', stuID, ''))
        print('}', end = '')
        flag = 1
    print(']')


import sys
# with open("teams.tsv", "w") as file:
with open("accounts.tsv", "w") as file:
    sys.stdout = file
    stuInfo = readData()
    # print(stuInfo)
    # examMakeTeamTSV(stuInfo)
    examEakeAccountTSV(stuInfo)
    # makeAccount(stuInfo)