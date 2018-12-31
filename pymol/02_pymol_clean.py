from pymol import cmd

import sys, os

'''
clean all pdb files in pdblib and save to the outlib.

only keep protein, ligand in the binding pocket, and solvent within 4 of protein.


Usage:
pymol -c pymol_clean.py pdblib outlib
'''

# center of binding pocket, radius that used to find ligand
CENTER = [-3.884,  -5.706, -13.967]
RADIUS = 10.0


# dir that contains pdb files
pdblib=sys.argv[3]

# all pdb files
allprots = sorted([i for i in os.listdir(pdblib) if i[-4:] in ['.pdb', '.PDB']])

# output dir
if pdblib.endswith('/'):
    outlib = '%s_cleaned' % os.path.dirname(pdblib)
else:
    outlib = '%s_cleaned' % pdblib

print "\nInput lib: %s\nOutput lib %s" %  (pdblib, outlib)
print 'Found %d pdb files from %s' % (len(allprots), pdblib)

# create output dir
try:
    os.makedirs(outlib)
except:
    pass

def get_most_appeared(resnames):
    if len(resnames) == 0:
        res = ''
    else:
        freq = {}
        for i in list(set(resnames)):
            freq[i] = resnames.count(i)
        res = sorted(freq, key=lambda x: freq[x], reverse=True)[0]
    return res

n = 1
for pr in allprots:
    cmd.reinitialize
    # load pr
    pr_name = pr.split('.pdb')[0]
    cmd.load('%s/%s' % (pdblib, pr))
    # add pseudoatom
    cmd.pseudoatom(object="%s" % pr_name, pos=CENTER)
    # get resname of the ligand close to the pocket center
    resnames = []
    cmd.iterate("(organic within %s of resn PSD)" % str(RADIUS), expression="resnames.append(resn)")    
    lig_resn = get_most_appeared(resnames)
    cmd.deselect()

    #print pr_name, lig_resn, len(resnames), resnames

    # selection string
    if len(lig_resn) == 0:
        cmd.select("sele_str", "(polymer.protein or solvent within 4 of polymer.protein)")
    else:
        cmd.select("sele_str", "(polymer.protein or resn %s)" % lig_resn)
        cmd.select("sele_str", "solvent within 4 of polymer.protein", merge=1)

    # save pr, lig, and water within 4 of pr
    cmd.save(filename='%s/%s.pdb' % (outlib, pr_name), selection='sele_str')

    cmd.delete(pr_name)
    n += 1



# quit pymol (don't miss!)
cmd.quit()
