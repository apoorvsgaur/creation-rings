from os import walk

path = "C:\Venturesity\Python_Scripts\Resume_Scraping\Resumes"
path = "C:\Venturesity\Python_Scripts\Resume_Scraping\Resumes Tags"
#path_tags = "C:\Venturesity\Python_Scripts\Resume_Scraping"
strings = []
pattern = r'[\w].[\w]'
for (dirpath, dirnames, filenames) in walk(path):
    #string = re.findall(pattern, filename)
    strings.extend(filenames)
    break

print strings
