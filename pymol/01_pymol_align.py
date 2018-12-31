from pymol import cmd

import sys, os

'''
align all pdb files from pdblib to prot1 and save to the outlib.

Usage:
pymol -c pymol_align.py pdblib outlib
'''

# benchmark protein
prot1="../workplace/aa2ar_4EIY/4EIY_refined_OPM_centered.pdb"
prot1_name=os.path.basename(prot1).split('.pdb')[0]

# dir that contains pdb files
pdblib=sys.argv[3]

# all pdb files
allprots = sorted([i for i in os.listdir(pdblib) if i[-4:] in ['.pdb', '.PDB']])

# output dir
if pdblib.endswith('/'):
    outlib = '%s_aligned' % os.path.dirname(pdblib)
else:
    outlib = '%s_aligned' % pdblib

print "\nInput lib: %s\nOutput lib %s" %  (pdblib, outlib)
print "Benchmark structure for alignment: %s" % prot1
print 'Found %d pdb files from %s' % (len(allprots), pdblib)

# create output dir
try:
    os.makedirs(outlib)
except:
    pass

n = 1
for pr in allprots:
    cmd.reinitialize
    cmd.load(prot1)
    pr_name = pr.split('.pdb')[0]
    cmd.load('%s/%s' % (pdblib, pr))

    cmd.align(pr_name, prot1_name)
    print "%d/%d Aligning %s to %s ..." % (n, len(allprots), pr_name, prot1_name)

    cmd.delete(prot1_name)
    cmd.save('%s/%s.pdb' % (outlib, pr_name))
    cmd.delete(pr_name)
    n += 1

# quit pymol (don't miss!)
cmd.quit()
