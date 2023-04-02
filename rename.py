import os, re, pathlib
def renamer(path, test=True):
    for _, old_name in enumerate(os.listdir(path)):
        if not re.match("^day\d+$", old_name): continue
        try:
            new_name = re.search("^day(\d+)$", old_name).group(1)
            new_name = "day" + ("0" if len(new_name)==1 else "") + new_name + pathlib.Path(old_name).suffix
            if (test): print(str(_)+") Preview name \""+new_name+"\"")
            elif (not os.rename(path+old_name, path+new_name)): print(str(_)+") File renamed \""+new_name+"\"")
        except:
            print(str(_)+") Error: \""+old_name+"\"")
renamer("./", False)
