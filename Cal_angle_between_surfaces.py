#!/Users/p6n/tools/anaconda2/bin/python

import numpy as np

def unit_vector(vector):
    """ Returns the unit vector of the vector.  """
    return vector / np.linalg.norm(vector)

def angle_between(v1, v2):
    """ Returns the angle in degree between vectors 'v1' and 'v2'::
    """
    v1_u = unit_vector(v1)
    v2_u = unit_vector(v2)
    return 180 * np.arccos(np.clip(np.dot(v1_u, v2_u), -1.0, 1.0))/np.pi

def string_to_vector(s):
    return np.array([float(i) for i in s.strip().split()])

def orthogonal_vector(p1, p2, p3):
    v1 = string_to_vector(p2) - string_to_vector(p1)
    v2 = string_to_vector(p3) - string_to_vector(p1)
    return np.cross(v1, v2)

def angle_between_surfaces(P1, P2, P3, P4, P5):
    # surface vectors
    a1 = unit_vector(orthogonal_vector(P1, P2, P3))
    a2 = unit_vector(orthogonal_vector(P1, P4, P5))

    # angle between surface vectors
    angle = angle_between(a1, a2)
    return angle


if __name__ == '__main__':
    # step1_1_metaHgS_init.xyz
    P1 = '6.22787833       8.80755000      25.56969583' # shared point
    P2 = '4.15191889      10.27547500      25.56969583' # plane 1
    P3 = '8.30383777      10.27547500      25.56969583' # plane 1
    P4 = '6.22787833       7.33962500      23.49373638' # plane 2
    P5 = '10.37979722       7.33962500      23.49373638' # plane 2

    angle = angle_between_surfaces(P1, P2, P3, P4, P5)
    print (angle)


    # step1_1_metaHgS_opted.xyz
    P1 = '6.2278783313        9.1104531054       25.1607138821' # shared point
    P2 = '4.1519187379       10.3302692433       25.7688299668' # plane 1
    P3 = '8.3038378244       10.3302695520       25.7688299993' # plane 1
    P4 = '6.2278781661        7.2769756439       23.4576829474' # plane 2
    P5 = '10.3797973276        7.2769757488       23.4576831392' # plane 2

    angle = angle_between_surfaces(P1, P2, P3, P4, P5)
    print (angle)


