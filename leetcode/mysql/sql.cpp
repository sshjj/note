1.用一条语句查询出每门课都大于80分的学生姓名
2.删除除了自动编号不同，其他都相同的学生冗余信息。
第一题数据：
name      course     score 
张三        语文        81
张三        数学        75
李四        语文        76
李四        数学        90
王五        语文        81
王五        数学        100
王五        英语        90
解决思路：使用聚合函数min(score)条件需要使用having语句。
select name from (select name,min(score)) from student group by name having min(score)>80 stu;