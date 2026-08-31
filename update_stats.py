import requests, json
r = requests.get('https://alfa-leetcode-api.onrender.com/emilyperry0/solved')
data = r.json()
with open('README.md', 'w') as f:
    f.write(f"""## Total Problems Solved: **{data['solvedProblem']}**  
    
Easy: **{data['easySolved']}**  
Medium: **{data['mediumSolved']}**  
Hard: **{data['hardSolved']}**""")