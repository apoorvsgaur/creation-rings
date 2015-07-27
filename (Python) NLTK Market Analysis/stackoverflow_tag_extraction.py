__author__ = 'Apoorv'
import urllib2
from bs4 import BeautifulSoup
import time

x=1204
all_tags = []
start_time = time.time()
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
           f.write(tag.img.contents[0].encode('utf8')+'\n')
       else:
           all_tags.append(tag.contents[0])
           f.write(tag.contents[0].encode('utf8')+'\n')
    f.close()
    x+=1
    print(len(all_tags))
    speed = len(all_tags)/(time.time() - start_time)
    print str(speed) + ' tags/second.'

f = open('tags_stackoverflow.txt', 'w')
for x in range(1,1204):
    with open('tags'+str(x)+'.txt') as tags_f:
        f.write(tags_f.read())
f.close()