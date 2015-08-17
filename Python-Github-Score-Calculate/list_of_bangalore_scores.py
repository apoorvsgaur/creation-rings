from user_score_calculate import github_score

list_usernames = []
github_scores = []
with open('github_venturesity_users.txt') as f:
     [list_usernames.append(i.replace("\n","")) for i in f.readlines()]

#print list_usernames
i = 1
for x in list_usernames:
     score = github_score(x)
     github_scores.append(score)
     with open('number_venturesity_users_done.txt','w') as f:
         f.write(str(i))
     i = i + 1
#
print github_scores
with open('github_venturesity_scores_1.txt','w') as f:
      for x in github_scores:
         f.write(str(x) + '\n')
