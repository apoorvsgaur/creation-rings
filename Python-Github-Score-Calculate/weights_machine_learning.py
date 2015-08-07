from numpy import matrix
from numpy.linalg import inv
from user_score_calculate import github_score

ideal_users = ['fabpot','kevinsawicki', 'michalbe', 'ornicar', 'snoyberg',  'rkh']
matrix_scores = []
i = 0
for x in ideal_users:
    matrix_scores.append(github_score(x))
    with open('number_users_done.txt','w') as f:
        f.write(str(i))
    i = i + 1

print matrix_scores

a = matrix('1713 142 2482 24548 10.099504938362077 35; 677 76 173 534 68.34660973335467 284530; \
644 89 768 3094 894.2428004878145 602829; 453 92 446 1147 569.5794107378251 150673; \
1370 83 194 2008 520.9929819365284 59536; 5164 6 110 539 39.79223426581228 1351')

b = matrix('100; 100; 100; 100; 100; 100')
print inv(a)*b
