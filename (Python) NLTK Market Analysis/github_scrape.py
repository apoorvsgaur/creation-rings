import urllib2
from bs4 import BeautifulSoup
import time
lang = 'PHP'
loc = 'pune'
urlp1 = 'https://github.com/search?l=' + lang + '&o=desc&p='

urlp2 = '&q=location%3A' + loc + '&s=followers&type=Users&utf8=%E2%9C%93'
fp = open('github-' + loc + '-' + lang + '.csv', 'w')
fp.write('user,fullName,email\n')
x = 0
print 'Kappa'
while(True):
    url = urlp1 + str(x+1) + urlp2
    html = ''
    while(True):
        try:
            html = urllib2.urlopen(url).read()
            break;
        except Exception as e:
            print e
            print('Sleeping for 120 seconds')
            time.sleep(120)

    soup = BeautifulSoup(html)
    userList = soup.find_all('div', {'class':'user-list-info'})
    if len(userList) == 0:
        print '-------------------------------------------------'
        print 'All done'
        break
    for u in userList:
        user = u.a.contents[0]
        fullName = u.contents[2].strip()
        print(userList)
        email = u.find_all('a', {'class':'email'})
        if len(email) == 1:
            email = email[0].contents[0]
        else:
            email = ''
            continue
        line = user + ',' + fullName + ',' + email
        print line
        fp.write(line + '\n')

    print('Page ' + str(x+1) + ' done.')
    print('-------------------------------------------------')
    print('Sleeping for 5 seconds')
    time.sleep(5)
    x += 1

fp.close()
