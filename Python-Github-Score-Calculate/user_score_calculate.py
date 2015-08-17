import json
import requests
import math
from bs4 import BeautifulSoup
import urllib2

def github_score(user):
    data = {}
    try:
        url = 'https://api.github.com/users/' + user + '?access_token=c9e62a0705e69d2d5ed041d1a1c27d853aded88f'
        html = requests.get(url).text
        data = json.loads(html)
        followers_score = data['followers']
        url = 'https://github.com/' + user
        html = urllib2.urlopen(url)
        soup = BeautifulSoup(html.read(), 'html.parser')
        contributions_tags = soup.find_all('span', {'class':'contrib-number'})
        #print contributions_tags[0].text.split(" ")[0]
        contributions = int(contributions_tags[0].text.split(" ")[0].replace(",",""))
    except Exception as e:
        print e
        return "Invalid User"

    page_count = 1
    repo_score = 0
    fork_score = 0
    star_score = 0
    commit_score = 0
    score = 0
    forked_repo_score = 0
    while(True):
        try:
                url = 'https://api.github.com/users/' + str(user) + '/repos?page=' + str(page_count) + '&per_page=1000&access_token=c9e62a0705e69d2d5ed041d1a1c27d853aded88f'
                html = requests.get(url).text
                data = json.loads(html)
                if (len(data) == 0):
                    break
                page_count = page_count + 1

        except:
                pass
            #print url

            #print data
        for x in data:
                try:
                   #print x['full_name']
                   if x['fork'] == False:
                       repo_score = repo_score + 1
                       fork_score = fork_score + x['forks']
                       star_score = star_score + x['stargazers_count']
                #    else:
                #         try:
                #             url = 'https://api.github.com/repos/' + x['full_name'] + '/stats/contributors?access_token=c9e62a0705e69d2d5ed041d1a1c27d853aded88f'
                #             #print url
                #             html = requests.get(url).text
                #             data = json.loads(html)
                #             number_lines = 0
                #             for y in data[0]['weeks']:
                #                 number_lines = number_lines + y['a'] + y['d']
                   #
                #             commit_repo = 0
                #             commit_repo = data[0]['total']
                #             #print data[-1]['author']['login']
                #             #print x['full_name'].split("/")[-1]
                #             url = 'https://api.github.com/repos/' + data[-1]['author']['login'] + "/" + x['full_name'].split("/")[-1] + '?access_token=c9e62a0705e69d2d5ed041d1a1c27d853aded88f'
                #             #print url
                #             html = requests.get(url).text
                #             data = json.loads(html)
                #             forks_repo = 0
                #             forks_repo = data['forks']
                #             forked_repo_score = forked_repo_score + math.sqrt(float(commit_repo)*float(forks_repo))
                #         except:
                #             pass
                except:#    print score
                    print x

    return  0.40718889*followers_score + 0.71465675*repo_score + 0.92279081*fork_score + 1.08102433*star_score + 0.1243854*contributions
    #return [followers_score,repo_score,fork_score,star_score,contributions]

#score = github_score("cyberhck")
#print score
