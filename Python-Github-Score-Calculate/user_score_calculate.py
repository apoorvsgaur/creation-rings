import json
import requests

def github_score(user):
    try:
        url = 'https://api.github.com/users/' + str(user) + '/repos?page=1&per_page=1000&access_token=c9e62a0705e69d2d5ed041d1a1c27d853aded88f'
        html = requests.get(url).text
    except:
#        print user
        return user
    #print url
    data = json.loads(html)
    #print data
    repo_score = 0
    number_lines = 0
    fork_score = 0
    star_score = 0
    commit_score = 0
    for x in data:
        try:
           print x['full_name']
           if x['fork'] == False:
               repo_score = repo_score + 1
               fork_score = fork_score + x['forks']
               star_score = star_score + x['stargazers_count']
           else:
                url = 'https://api.github.com/repos/' + x['full_name'] + '/stats/contributors'
                #print url
                html = requests.get(url).text
                data = json.loads(html)
                commit_repo = 0
                commit_repo = data[0]['total']
                for x in data[0]['weeks']:
                    number_lines = number_lines + x['a'] + x['d']


        except:#    print score
            return score

score = github_score("cyberhck")
#print score
