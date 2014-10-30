__author__ = 'ee364a11'

import glob

def getRegistration():
    check_files = glob.glob('./EECS???.txt')
    Student_ID = {}
    Final_List = {}
    with open('./students.txt', 'r') as open_file:
      lines = open_file.readlines()
      for l in lines:
        words = l.split("|")
        if (words[0] != "Student Name" and len(words) != 1):
          #print words[0]
          Student_ID[words[0].strip()] = words[1].strip()

    for k in check_files:
      s = set()
      with open(k, 'r') as open_file:
        lines = open_file.readlines()
        for l in lines:
           id_numbers = l.split()
           for key, values in Student_ID.items():
               if (id_numbers[0] == values):
                  if (key not in  Final_List):
                    t = (k[6:9], id_numbers[1])
                    s.add(t)
                  else:
                    t = (k[6:9], id_numbers[1])
                    s.add(t)
                  Final_List[key] = s
    print (Final_List)

def getRoster(classNumber):
   check_files = glob.glob('./EECS???.txt')
   Student_ID = {}
   List_Names = {}
   with open('./students.txt', 'r') as open_file:
      lines = open_file.readlines()
      for l in lines:
         words = l.split("|")
         if (words[0] != "Student Name" and len(words) != 1):
            Student_ID[words[0].strip()] = words[1].strip()

   for k in check_files:
      with open(k, 'r') as open_file:
        if (classNumber == int(k[6:9])):
           lines = open_file.readlines()
           for l in lines:
              id_numbers = l.split()
              for key, values in Student_ID.items():
                  if (id_numbers[0] == values):
                      List_Names[key] = key
   return List_Names.values()

def getStudentInfoByName(studentName):
    available_list = getRegistration()
    for key, values in available_list:
        if (key == studentName):
            return (values)
    return ({})

def getStudentInfoByID(studentID):
    available_list = getRegistration()
    print (available_list)
    Student_ID = {}
    with open('./students.txt', 'r') as open_file:
      lines = open_file.readlines()
      for l in lines:
        words = l.split("|")
        if (words[0] != "Student Name" and len(words) != 1):
          #print words[0]
          Student_ID[words[0].strip()] = words[1].strip()

    for key, values in Student_ID:
       if (values == studentID):
           return (available_list[key])
    return {}

#def getStudentGrade(studentName, classNumber):
#    class_list = getRegistration()






if __name__ == "__main__":
   getRegistration()
  # getRoster(375)
  # getStudentInfoByName('Johnny W Evans')
  # getStudentInfoByID('02583-95216')
