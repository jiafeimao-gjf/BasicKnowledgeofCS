### SQL 练习
```sql
# 员工表
CREATE TABLE `employees` (
`emp_no` int(11) NOT NULL,
`birth_date` date NOT NULL,
`first_name` varchar(14) NOT NULL,
`last_name` varchar(16) NOT NULL,
`gender` char(1) NOT NULL,
`hire_date` date NOT NULL,
PRIMARY KEY (`emp_no`));
```

1. 查找最晚入职的员工的所有信息
- 日期越大，越晚入职，max函数
```sql
select * from employees where hire_date = (select max(hire_date) from employees)
```
2. 查找入职员工时间排名倒数第三的员工所有信息
- order by, distinct, desc limit 的使用
```sql
select * from employees where hire_date = (
    select distinct hire_date from employees order by hire_date desc limit 2,1
)
```

```sql
# 部门经理表
CREATE TABLE `dept_manager` (
`dept_no` char(4) NOT NULL,
`emp_no` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));
# 工资表
CREATE TABLE `salaries` (
`emp_no` int(11) NOT NULL,
`salary` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`from_date`));
```
3. 查找各个部门当前(to_date='9999-01-01')领导当前薪水详情，以及其对应部门编号dept_no
- 联表查询
```sql
select s.* ,d.dept_no from salaries as s join dept_manager  as d 
    on s.emp_no = d.emp_no 
    where s.to_date = '9999-01-01' and d.to_date = '9999-01-01'
```

```sql
# 部门员工表
CREATE TABLE `dept_emp` (
`emp_no` int(11) NOT NULL,
`dept_no` char(4) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));
# 职工表
CREATE TABLE `employees` (
`emp_no` int(11) NOT NULL,
`birth_date` date NOT NULL,
`first_name` varchar(14) NOT NULL,
`last_name` varchar(16) NOT NULL,
`gender` char(1) NOT NULL,
`hire_date` date NOT NULL,
PRIMARY KEY (`emp_no`));
```
4. 查找所有已经分配部门的员工的last_name和first_name
- inner join ... on ...
```sql
select e.last_name,e.first_name,de.dept_no
    from dept_emp as de
    inner join employees as e 
    on de.emp_no = e.emp_no;
```
5. 查找所有员工的last_name和first_name以及对应部门编号dept_no，也包括展示没有分配具体部门的员工

- INNER JOIN 两边表同时有对应的数据，即任何一边缺失数据就不显示。
- LEFT JOIN 会读取左边数据表的全部数据，即便右边表无对应数据。
- RIGHT JOIN 会读取右边数据表的全部数据，即便左边表无对应数据。
```sql
select e.last_name,e.first_name,de.dept_no
    from employees as e 
    left join dept_emp as de 
    on de.emp_no = e.emp_no;
```
6. 查找所有员工入职时候的薪水情况，给出emp_no以及salary， 并按照emp_no进行逆序

```sql
# way 1
select e.emp_no,s.salary 
    from employees as e
    inner join salaries as s
    on e.hire_date = s.from_date and e.emp_no = s.emp_no
    order by e.emp_no desc;

# way 2
select e.emp_no,s.salary
    from employees as e,salaries as s
    where e.emp_no = s.emp_no and e.hire_date = s.from_date
    order by e.emp_no desc

```
7. 查找薪水变化超过15次的员工号emp_no以及其对应的变化次数t
- group by 属性 having 条件
```sql
select emp_no,count(emp_no) as t from salaries
    group by emp_no having t > 15;
```

8. 找出所有员工当前(to_date='9999-01-01')具体的薪水salary情况，对于相同的薪水只显示一次,并按照逆序显示
- 对于distinct与group by的使用: 
    - 当对系统的性能高并数据量大时使用group by 
    - 当对系统的性能不高时使用数据量少时两者皆可 
    - 尽量使用group by
```sql
select distinct salary from salaries
    where to_date = '9999-01-01'
    order by salary desc

select salary from salaries
    where to_date = '9999-01-01'
    group by salary
    order by salary desc
```
9. 获取所有部门当前manager的当前薪水情况，给出dept_no, emp_no以及salary，当前表示to_date='9999-01-01'

```sql
select d.dept_no,d.emp_no,s.salary 
    from dept_manager as d
    inner join salaries as s
    on d.emp_no = s.emp_no
    and d.to_date = '9999-01-01' 
    and s.to_date = '9999-01-01'
    group by d.emp_no;
```
10. 获取所有非manager的员工emp_no
- not in 
```sql
# use : not in
select e.emp_no 
    from employees as e
    where e.emp_no not in (
    select d.emp_no from dept_manager as d
)
# 使用 left join 和 NULL
SELECT employees.emp_no FROM employees 
    LEFT JOIN dept_manager
    ON employees.emp_no = dept_manager.emp_no
WHERE dept_no IS NULL
```  
11. 获取员工当前的manager  
- 获取所有员工当前的manager，如果当前的manager是自己的话结果不显示，当前表示to_date='9999-01-01'。
- 结果第一列给出当前员工的emp_no,第二列给出其manager对应的manager_no。
```sql
select de.emp_no,dm.emp_no AS manager_no 
    from dept_emp as de inner join dept_manager as dm 
    on de.dept_no = dm.dept_no -- 部门一致
    -- 时间期限限定 manager自己不用显示（员工表的员工号不应该与部门表的员工号一致）
    where dm.to_date = '9999-01-01' AND de.to_date = '9999-01-01' AND de.emp_no <> dm.emp_no

```
12. 获取所有部门中当前员工薪水最高的相关信息
- 获取所有部门中当前员工薪水最高的相关信息，给出dept_no, emp_no以及其对应的salary
```sql
select d.dept_no,s.emp_no,max(s.salary) as salary
    from salaries as s inner join dept_emp as d
    on d.emp_no = s.emp_no
    where d.to_date = '9999-01-01' and s.to_date = '9999-01-01'
    -- group by 的分组功能，分了组就会取每组的最大值
    group by d.dept_no

```
13. 从titles表获取按照title进行分组
从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。
```sql
CREATE TABLE IF NOT EXISTS "titles" (
`emp_no` int(11) NOT NULL,
`title` varchar(50) NOT NULL,
`from_date` date NOT NULL,
`to_date` date DEFAULT NULL);
```
```sql
select title,count(title) as t 
    from titles
    group by title
    -- 条件：title的数量大于等于2
    -- 由于WHERE后不可跟COUNT()函数，故用HAVING语句来限定t>=2的条件
    having t >= 2
```
14. 从titles表获取按照title进行分组，注意对于重复的emp_no进行忽略。
- 从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。
- 注意对于重复的emp_no进行忽略。
```sql
-- distinct emp_no 避免emp_no重复
select title,count(distinct emp_no) as t 
    from titles
    group by title
    -- 条件：title的数量大于等于2
    -- 由于WHERE后不可跟COUNT()函数，故用HAVING语句来限定t>=2的条件
    having t >= 2
```
15. 查找employees表
- 查找employees表所有emp_no为奇数，且last_name不为Mary的员工信息，并按照hire_date逆序排列
```sql
select * from employees
    -- 字符串 要用: ''
    where emp_no % 2 = 1 and last_name != 'Mary'
    -- order by XXX desc 表示按照 XXX 逆序
    order by hire_date desc
```
16. 统计出当前各个title类型对应的员工当前薪水对应的平均工资
- 统计出当前各个title类型对应的员工当前（to_date='9999-01-01'）薪水对应的平均工资。结果给出title以及平均工资avg。
```sql
select t.title,avg(s.salary)
    from salaries as s inner join titles as t
    on s.emp_no = t.emp_no
    where s.to_date = '9999-01-01' and t.to_date = '9999-01-01'
    group by t.title
```
17. 获取当前薪水第二多的员工的emp_no以及其对应的薪水salary
- 获取当前（to_date='9999-01-01'）薪水第二多的员工的emp_no以及其对应的薪水salary
- select * from table limit [m],n;
- 其中
    - m—— [m]为可选，如果填写表示skip步长，即跳过m条。
    - n——显示条数。指从第m+1条记录开始，取n条记录。
```sql
select emp_no,salary
    from salaries
    where to_date  = '9999-01-01' and 
    -- order by 排序
    -- desc 逆序
    -- limit 限制从第几位开始
    salary = (select distinct salary from salaries order by salary desc limit 1,1)
```
18. 获取当前薪水第二多的员工的emp_no以及其对应的薪水salary，不准使用order by
- 多级查询，
- 不等于号 <>
- max函数
```sql
select e.emp_no,s.salary,e.last_name,e.first_name 
    from employees as e inner join salaries as s
    on e.emp_no = s.emp_no
    where to_date = '9999-01-01' and 
        salary = (
        select max(salary) from salaries
        where salary <> (select max(salary) from salaries where to_date = '9999-01-01')
        and to_date = '9999-01-01'
    )
```
19. 查找所有员工的last_name和first_name以及对应的dept_name
- 查找所有员工的last_name和first_name以及对应的dept_name，也包括暂时没有分配部门的员工
```sql
select e.last_name,e.first_name,dp.dept_name 
    from (employees as e left join dept_emp as de on e.emp_no = de.emp_no)
    left join departments as dp on dp.dept_no = de.dept_no
```
20. 查找员工编号emp_no为10001其自入职以来的薪水salary涨幅值growth
- min 和 max
```sql
-- way 1
select (max(salary) - min(salary)) as growth 
    from salaries where emp_no = '10001'

-- way 2
select (    
    (select salary from salaries where emp_no = '10001' order by to_date  desc limit 1) -
    (select salary from salaries where emp_no = '10001' order by to_date asc limit 1)
    ) 
    as growth 
```
21. 查找所有员工自入职以来的薪水涨幅情况，给出员工编号emp_no以及其对应的薪水涨幅growth，并按照growth进行升序
- 综合使用left join 
- order by
- 根据所给表格，找出查找所需数据的条件
```sql
select sCurrent.emp_no,(sCurrent.salary-sStart.salary) as growth
from (select s.emp_no,s.salary from employees e left join salaries s on e.emp_no = s.emp_no where s.to_date = '9999-01-01') as sCurrent
inner join (select s.emp_no,s.salary from employees e left join salaries s on e.emp_no = s.emp_no where s.from_date = e.hire_date) as sStart
on sCurrent.emp_no = sStart.emp_no
order by growth
```
22. 统计各个部门对应员工涨幅的次数总和，给出部门编码dept_no、部门名称dept_name以及次数sum
- 按照部门id分组，查询所有员工的工资
- 
```sql
-- 简单解法
select dm.dept_no,dm.dept_name,count(*) as sum
    from departments as dm,dept_emp as de,salaries as s
    where s.emp_no = de.emp_no and dm.dept_no = de.dept_no
    group by dm.dept_no
-- 利用join，和上面一样的？
SELECT de.dept_no, dp.dept_name, COUNT(s.salary) AS sum 
FROM (dept_emp AS de INNER JOIN salaries AS s ON de.emp_no = s.emp_no) 
INNER JOIN departments AS dp ON de.dept_no = dp.dept_no 
GROUP BY de.dept_no
```

23. 对所有员工的当前(to_date='9999-01-01')薪水按照salary进行按照1-N的排名，相同salary并列且按照emp_no升序排列
- 按照薪水排名
- 按照emp_no排名
- 排名累计
```sql
-- 求排名： s1.salary <= s2.salary，意思是在输出s1.salary的情况下，有多少个s2.salary大于等于s1.salary，
select s1.emp_no,s1.salary,count(distinct s2.salary) as rank
from salaries as s1,salaries as s2
-- 找到满足时间条件的数据，和排序数据条件
where s1.to_date = '9999-01-01' and s2.to_date = '9999-01-01' and s1.salary <= s2.salary
-- 按照emp_no 进行分组
group by s1.emp_no
-- 进行排序，按照两个属性排序
order by s1.salary desc,s1.emp_no asc
```

24. 获取所有非manager员工当前的薪水情况，给出dept_no、emp_no以及salary ，当前表示to_date='9999-01-01'
- 一步一步来
    - 先找出所有满足时间条件的工资数据
    - 然后将工资数据与部门no绑定
    - 去除其中的manager的工资数据
```sql
select de.dept_no,s.emp_no,s.salary
from (employees as e inner join salaries as s on s.emp_no = e.emp_no and s.to_date = '9999-01-01')
inner join dept_emp as de on e.emp_no = de.emp_no
where de.emp_no not in (select emp_no from dept_manager where to_date = '9999-01-01')
```

25. 获取员工其当前的薪水比其manager当前薪水还高的相关信息，当前表示to_date='9999-01-01',
- 结果第一列给出员工的emp_no，
- 第二列给出其manager的manager_no，
- 第三列给出该员工当前的薪水emp_salary,
- 第四列给该员工对应的manager当前的薪水manager_salary

- 先获取所有员工的工资、和部门信息
- 再获取所有经理的工资、和部门信息
- 将部门相同的员工和经理的工资进行比较，求员工工资高于经理工资的信息
```sql
select des.emp_no as emp_no,dms.emp_no as manager_no,des.salary as emp_salary,dms.salary as manager_salary 
from
    (select s.emp_no,s.salary,de.dept_no 
     from salaries as s 
     inner join dept_emp as de 
     on s.emp_no = de.emp_no and s.to_date = '9999-01-01') as des,
    (select s.emp_no,s.salary,dm.dept_no 
     from salaries as s 
     inner join dept_manager as dm 
     on s.emp_no = dm.emp_no and s.to_date = '9999-01-01') as dms
where des.dept_no = dms.dept_no and des.salary > dms.salary
```