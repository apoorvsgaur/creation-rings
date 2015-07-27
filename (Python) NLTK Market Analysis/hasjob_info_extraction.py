__author__ = 'Apoorv'
import urllib2
from bs4 import BeautifulSoup
import re
import time
with open('hasjob-job-urls.txt') as f:
    data = f.read().split('\n')

unique_code =[]

final = open('final.txt', 'w');
for x in range(0,len(data)):
   url = 'http://hasjob.co' + data[x]
   while(True):
        try:
            html_imp = urllib2.urlopen(url).read()
            break;
        except Exception as e:
           print e
           break;


   soup = BeautifulSoup(html_imp)
   if(soup.find_all('div',{'class':'col-md-9 jobdescription'})):
      sec = soup.find_all('div',{'class':'col-md-9 jobdescription'})[0]

   #print(sec)
   #pattern = r'</-/[/]/w>'

   pat_tag = r'<[\[\]\-!/\w \.\?;"=:]*>'
   content = re.sub(pat_tag, '', str(sec))
   pat_code = r'/[\w\.][/\w=]*'
   patterm_w = re.findall(pat_code, data[x])
   final.write(content + '\n')

   with open(str(x) + '. JD ' + '.txt','w') as f:
       f.write(content + '\n')

final.close()


