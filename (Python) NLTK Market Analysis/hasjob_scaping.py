__author__ = 'Apoorv'

import urllib2
from bs4 import BeautifulSoup

with open('hasjob_HTML.txt') as f:
    data = f.read()

soup = BeautifulSoup(data)
data_urls = soup.find_all('a',{'class':'stickie'})
urls = []
for x in data_urls:
    urls.append(x['href'])
print urls
fp = open('hasjob-job-urls.txt', 'w')
fp.write('\n'.join(urls))
fp.close()
