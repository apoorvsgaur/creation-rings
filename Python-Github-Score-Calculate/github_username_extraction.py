import urllib2
from bs4 import BeautifulSoup
import os

x=1
f = open('github_bangalore_users.txt', 'w')
while(x < 101):
   while(True):
       try:
           url = "https://github.com/search?p=" + str(x) + "&q=location%3Abangalore&type=Users&utf8=%E2%9C%93"
           html = urllib2.urlopen(url).read()
           break;
       except:
           pass
   soup = BeautifulSoup(html, "html.parser")
   b = soup.find_all('div', {"class":"user-list-info"})
   if (len(b) == 0):
        break;
   file = open(os.path.expanduser("~/Desktop/usernames/") + str(x) + ".txt", "w")
   for y in b:
      a = y.find_all('a')[0].text
      file.write(a + "\n")
      f.write(a + "\n")
   file.close()
   x = x + 1
f.close()
