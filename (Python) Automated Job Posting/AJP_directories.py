import os
import platform

def make_folder(portal):
    if not os.path.exists(os.path.expanduser("~/Desktop/Job Postings/" + portal)):
         os.mkdir(os.path.expanduser("~/Desktop/Job Postings/" + portal))

if (platform.system() == "Windows" or platform.system() == "Darwin"):
    pass
else:
    if not os.path.exists(os.path.expanduser("~/Desktop/Job Postings")):
         os.mkdir(os.path.expanduser("~/Desktop/Job Postings"))

    Jobs = ['OLX', 'Quickr', 'Indeed', 'Hasjob', 'Hirist', 'Trovit']
    for x in Jobs:
        make_folder(x)
