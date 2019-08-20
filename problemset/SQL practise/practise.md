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

```sql

```

```sql

```

```sql

```

```sql

```

```sql

```