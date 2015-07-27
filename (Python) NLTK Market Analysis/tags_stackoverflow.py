__author__ = 'Apoorv'

import time
import urllib2
from bs4 import BeautifulSoup

x=1
all_tags = []
start_time = time.time()
m_file = open('merged_file.txt','w')
while(True):
    url = "http://stackoverflow.com/tags?page=" + str(x) + "&tab=popular"
    html = ''

    while(True):
        try:
            html = urllib2.urlopen(url).read()
            break;
        except Exception as e:
            print e
            time.sleep(5)

    soup = BeautifulSoup(html)
    tagList = soup.find_all('a', {'class':'post-tag'})
    if(len(tagList) == 0):
        break;

    f = open("tags"+str(x)+".txt",'w')
    for tag in tagList:
       if(tag.img):
           all_tags.append(tag.img.contents[0])
           m_file.write(tag.img.contents[0]+'\n')
           f.write(tag.img.contents[0]+'\n')
       else:
           all_tags.append(tag.contents[0])
           m_file.write(tag.contents[0]+'\n')
           f.write(tag.contents[0]+'\n')
    f.close()
    x+=1
    print(len(all_tags))
    speed = len(all_tags)/(time.time() - start_time)
    print str(speed) + ' tags/second.'
m_file.close()
