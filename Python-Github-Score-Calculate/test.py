import numpy as np
from numpy import matrix
from numpy.linalg import inv
from user_score_calculate import github_score

a = matrix(' 234.            30.           813.          2770.            71.49352422;\
  157.            76.           313.          1872.           282.68762735;\
 163.             5.           384.          1156.            0.;\
  44.            19.           156.          1522.            47.67581283;\
 41.            14.           283.          1113.           112.48977685;\
 34.             5.           161.          1210.            16.50474305\
 ')

b = matrix('100; 100; 100; 100; 100; 100')
print inv(np.transpose(a)*a)*np.transpose(a)*b
