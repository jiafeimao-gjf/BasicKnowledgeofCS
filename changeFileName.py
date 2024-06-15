import os


if __name__ == "__main__":
    print("change file Name")
    profix = ""
    code_path = "./jiafeiblog/source/_posts/"
    if os.path.exists(code_path):
        for fileName in os.listdir(code_path):
            print(fileName)
            if not fileName.startswith("sword-"):
                with open(code_path + fileName,mode='r+',encoding="utf-8") as f:
                    content = f.read()
                    if content.find("- 剑指offer") != -1:
                        with open(code_path + "sword-"+fileName,mode='w+',encoding="utf-8") as nf:
                            nf.write(content)

                        print("new file:", "sword-"+fileName)
                
                        os.remove(code_path + fileName)



