from user_score_calculate import github_score

list_usernames = []
github_scores = []
with open('github_bangalore_users.txt') as f:
     [list_usernames.append(i.replace("\n","")) for i in f.readlines()]

for x in list_usernames:
    score = github_score(x)
    github_scores.append(score)

print github_scores
with open('github_scores.txt','w') as f:
     f.write(",".join(sorted(github_scores)))
