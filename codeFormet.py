#!/usr/bin/python
# -*- coding: UTF-8 -*- 


import os, datetime

suffix = "leetcode/"
code_path = "./problemset/" + suffix
code_format_path = "./problemset-publish/" + suffix

if __name__ == "__main__":
    if os.path.exists(code_path):
        print('code path exist')
        for fileName in os.listdir(code_path):
            print(fileName)
            cf_out = open(code_format_path + fileName, mode="w", encoding="utf-8-sig")
            
            # ---
            # title: 机器人的活动范围
            # categories:
            # - 算法题集
            # tags:
            # - 深度优先搜索
            # date: 2019-12-26 23:12:31
            # ---
            cf_out.write("---\n")
            cf_out.write("title: " + fileName.split(".")[0]+"\n")
            cf_out.write("categories:\n")
            cf_out.write("- leetcode\n")
            cf_out.write("tags:\n")
            cf_out.write("  - null\n")
            now_time = datetime.datetime.now()
            t_str = datetime.datetime.strftime(now_time,'%Y-%m-%d %H:%M:%S')
            cf_out.write("date: " + t_str + "\n")
            cf_out.write("---\n\n")
            with open(code_path + fileName, mode="r") as cf:
                line = cf.readline()
                while line:
                    cf_out.write(line)
                    line = cf.readline()

            cf_out.close()
    else:
        print('code path not exist')