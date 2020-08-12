# SELECT
select 列名 from 表名： select lastname,firstname from persons
select* from 表名: select * from persons
## select distinct
返回唯一不同的值
select disitinct 列名称 from 表名称
# where
select 列名 from 表名 where 列 运算符 值
select * from persons where city = 'beijing'
## and 和 or
在where子语句中把两个或多个条件结合起来
and : select *from persons where firstname = 'Thomas' AND lastname = 'Carter';
or:select *from persons where firstname = 'Thomas' OR lastname = 'Carter';
## order by
根据指定的列对结果进行排序，默认按升序排序，按降序使用DESC关键字
以字母顺序显示公司名称：
    SELECT Company, OrderNumber FROM Orders ORDER BY Company
以字母顺序显示公司名称（Company），并以数字顺序显示顺序号（OrderNumber）:
    SELECT Company, OrderNumber FROM Orders ORDER BY Company, OrderNumber
以逆字母顺序显示公司名称，并以数字顺序显示顺序号：
    SELECT Company, OrderNumber FROM Orders ORDER BY Company DESC, OrderNumber ASC
# insert into
INSERT INTO 语句用于向表格中插入新的行。

语法
INSERT INTO 表名称 VALUES (值1, 值2,....)
我们也可以指定所要插入数据的列：
INSERT INTO table_name (列1, 列2,...) VALUES (值1, 值2,....)
INSERT INTO Persons VALUES ('Gates', 'Bill', 'Xuanwumen 10', 'Beijing')
INSERT INTO Persons (LastName, Address) VALUES ('Wilson', 'Champs-Elysees')

# update
UPDATE 表名称 SET 列名称 = 新值 WHERE 列名称 = 某值
更新某一行中的一个列
    UPDATE Person SET FirstName = 'Fred' WHERE LastName = 'Wilson' 
更新某一行中的若干列
    UPDATE Person SET Address = 'Zhongshan 23', City = 'Nanjing' WHERE LastName = 'Wilson'

# delete
DELETE FROM 表名称 WHERE 列名称 = 值
删除某行
"Fred Wilson" 会被删除：
    DELETE FROM Person WHERE LastName = 'Wilson' 
# TOP
TOP 子句用于规定要返回的记录的数目。
SELECT TOP number|percent column_name(s) FROM table_name
现在，我们希望从上面的 "Persons" 表中选取头两条记录。
    SELECT TOP 2 * FROM Persons

# LIKE 操作符
LIKE 操作符用于在 WHERE 子句中搜索列中的指定模式。
SELECT column_name(s)
FROM table_name
WHERE column_name LIKE pattern

现在，我们希望从上面的 "Persons" 表中选取居住在以 "N" 开始的城市里的人：
我们可以使用下面的 SELECT 语句：
    SELECT * FROM Persons
    WHERE City LIKE 'N%'
    "%" 可用于定义通配符（模式中缺少的字母）
接下来，我们希望从 "Persons" 表中选取居住在包含 "lon" 的城市里的人：
我们可以使用下面的 SELECT 语句：
    SELECT * FROM Persons
    WHERE City LIKE '%lon%'
# SQL通配符
在搜索数据库中的数据时，SQL 通配符可以替代一个或多个字符。
SQL 通配符必须与 LIKE 运算符一起使用。
在 SQL 中，可使用以下通配符：

通配符	                             描述
%	                            替代一个或多个字符
_	                            仅替代一个字符
[charlist]	                    字符列中的任何单一字符
[^charlist]/[!charlist]        不在字符列中的任何单一字符

使用 [charlist] 通配符
现在，我们希望从上面的 "Persons" 表中选取居住的城市以 "A" 或 "L" 或 "N" 开头的人：
我们可以使用下面的 SELECT 语句：
    SELECT * FROM Persons
    WHERE City LIKE '[ALN]%'
# IN
IN 操作符允许我们在 WHERE 子句中规定多个值。
SQL IN 语法
SELECT column_name(s)
FROM table_name
WHERE column_name IN (value1,value2,...)
现在，我们希望从上表中选取姓氏为 Adams 和 Carter 的人：
我们可以使用下面的 SELECT 语句：
    SELECT * FROM Persons
    WHERE LastName IN ('Adams','Carter')
# BWETWEEN
操作符 BETWEEN ... AND 会选取介于两个值之间的数据范围。这些值可以是数值、文本或者日期。
SQL BETWEEN 语法
SELECT column_name(s)
FROM table_name
WHERE column_name
BETWEEN value1 AND value2
# AS
表的 SQL Alias 语法
    SELECT column_name(s)
    FROM table_name
    AS alias_name
列的 SQL Alias 语法
    SELECT column_name AS alias_name
    FROM table_name
SELECT po.OrderID, p.LastName, p.FirstName
FROM Persons AS p, Product_Orders AS po
WHERE p.LastName='Adams' AND p.FirstName='John'

# JION
SQL join 用于根据两个或多个表中的列之间的关系，从这些表中查询数据。
有时为了得到完整的结果，我们需要从两个或更多的表中获取结果。我们就需要执行 join。
数据库中的表可通过键将彼此联系起来。主键（Primary Key）是一个列，在这个列中的每一行的值都是唯一的。在表中，每个主键的值都是唯一的。这样做的目的是在不重复每个表中的所有数据的情况下，把表间的数据交叉捆绑在一起。

引用两个表
我们可以通过引用两个表的方式，从两个表中获取数据：
谁订购了产品，并且他们订购了什么产品？
    SELECT Persons.LastName, Persons.FirstName, Orders.OrderNo
    FROM Persons, Orders
    WHERE Persons.Id_P = Orders.Id_P 

除了上面的方法，我们也可以使用关键词 JOIN 来从两个表中获取数据。
如果我们希望列出所有人的定购，可以使用下面的 SELECT 语句：
    SELECT Persons.LastName, Persons.FirstName, Orders.OrderNo
    FROM Persons
    INNER JOIN Orders
    ON Persons.Id_P = Orders.Id_P
    ORDER BY Persons.LastName

除了我们在上面的例子中使用的 INNER JOIN（内连接），我们还可以使用其他几种连接。
下面列出了您可以使用的 JOIN 类型，以及它们之间的差异。
JOIN: 如果表中有至少一个匹配，则返回行
LEFT JOIN: 即使右表中没有匹配，也从左表返回所有的行
RIGHT JOIN: 即使左表中没有匹配，也从右表返回所有的行
FULL JOIN: 只要其中一个表中存在匹配，就返回行

# UNION
UNION 操作符用于合并两个或多个 SELECT 语句的结果集。

请注意，UNION 内部的 SELECT 语句必须拥有相同数量的列。列也必须拥有相似的数据类型。同时，每条 SELECT 语句中的列的顺序必须相同。

SQL UNION 语法
SELECT column_name(s) FROM table_name1
UNION
SELECT column_name(s) FROM table_name2
注释：默认地，UNION 操作符选取不同的值。如果允许重复的值，请使用 UNION ALL。

SQL UNION ALL 语法
SELECT column_name(s) FROM table_name1
UNION ALL
SELECT column_name(s) FROM table_name2

# SELECT INTO
SELECT INTO 语句从一个表中选取数据，然后把数据插入另一个表中。
SELECT INTO 语句常用于创建表的备份复件或者用于对记录进行存档。
SQL SELECT INTO 语法
您可以把所有的列插入新表：
SELECT *
INTO new_table_name [IN externaldatabase] 
FROM old_tablename

或者只把希望的列插入新表：
SELECT column_name(s)
INTO new_table_name [IN externaldatabase] 
FROM old_tablename

# CREATE DATABASE 语句
CREATE DATABASE 语句
CREATE DATABASE 用于创建数据库。

SQL CREATE DATABASE 语法
CREATE DATABASE database_name
SQL CREATE DATABASE 实例
现在我们希望创建一个名为 "my_db" 的数据库。

我们使用下面的 CREATE DATABASE 语句：

CREATE DATABASE my_db
可以通过 CREATE TABLE 来添加数据库表。

# CREATE TABLE 语句
CREATE TABLE 语句用于创建数据库中的表。

SQL CREATE TABLE 语法
CREATE TABLE 表名称
(
列名称1 数据类型,
列名称2 数据类型,
列名称3 数据类型,
....
)
# SQL 约束 (Constraints)
约束用于限制加入表的数据的类型。
可以在创建表时规定约束（通过 CREATE TABLE 语句），或者在表创建之后也可以（通过 ALTER TABLE 语句）。
wo 们将主要探讨以下几种约束：

NOT NULL
UNIQUE
PRIMARY KEY
FOREIGN KEY
CHECK
DEFAULT
## NOT NULL 约束
NOT NULL 约束强制列不接受 NULL 值。
CREATE TABLE Persons
(
Id_P int NOT NULL,
LastName varchar(255) NOT NULL,
FirstName varchar(255),
Address varchar(255),
City varchar(255)
)
## SQL UNIQUE 约束
UNIQUE 约束唯一标识数据库表中的每条记录。

UNIQUE 和 PRIMARY KEY 约束均为列或列集合提供了唯一性的保证。

PRIMARY KEY 拥有自动定义的 UNIQUE 约束。

请注意，每个表可以有多个 UNIQUE 约束，但是每个表只能有一个 PRIMARY KEY 约束。

SQL UNIQUE Constraint on CREATE TABLE
下面的 SQL 在 "Persons" 表创建时在 "Id_P" 列创建 UNIQUE 约束：

MySQL:
CREATE TABLE Persons
(
Id_P int NOT NULL,
LastName varchar(255) NOT NULL,
FirstName varchar(255),
Address varchar(255),
City varchar(255),
UNIQUE (Id_P)
)

## PRIMARY KEY 约束
SQL Unique
SQL Foreign Key
SQL PRIMARY KEY 约束
PRIMARY KEY 约束唯一标识数据库表中的每条记录。

主键必须包含唯一的值。

主键列不能包含 NULL 值。

每个表都应该有一个主键，并且每个表只能有一个主键。
SQL PRIMARY KEY Constraint on CREATE TABLE
下面的 SQL 在 "Persons" 表创建时在 "Id_P" 列创建 PRIMARY KEY 约束：

MySQL:
CREATE TABLE Persons
(
Id_P int NOT NULL,
LastName varchar(255) NOT NULL,
FirstName varchar(255),
Address varchar(255),
City varchar(255),
PRIMARY KEY (Id_P)
)
## CREATE INDEX 语句
CREATE INDEX 语句用于在表中创建索引。
在不读取整个表的情况下，索引使数据库应用程序可以更快地查找数据。
索引
您可以在表中创建索引，以便更加快速高效地查询数据。
用户无法看到索引，它们只能被用来加速搜索/查询。

SQL CREATE INDEX 语法
在表上创建一个简单的索引。允许使用重复的值：

CREATE INDEX index_name
ON table_name (column_name)
注释："column_name" 规定需要索引的列。

SQL CREATE UNIQUE INDEX 语法
在表上创建一个唯一的索引。唯一的索引意味着两个行不能拥有相同的索引值。

CREATE UNIQUE INDEX index_name
ON table_name (column_name)
CREATE INDEX 实例
本例会创建一个简单的索引，名为 "PersonIndex"，在 Person 表的 LastName 列：

CREATE INDEX PersonIndex
ON Person (LastName) 
如果您希望以降序索引某个列中的值，您可以在列名称之后添加保留字 DESC：

CREATE INDEX PersonIndex
ON Person (LastName DESC) 
假如您希望索引不止一个列，您可以在括号中列出这些列的名称，用逗号隔开：

CREATE INDEX PersonIndex
ON Person (LastName, FirstName)

## 撤销索引、表以及数据库
通过使用 DROP 语句，可以轻松地删除索引、表和数据库。

SQL DROP INDEX 语句
我们可以使用 DROP INDEX 命令删除表格中的索引。

用于 MySQL 的语法:
ALTER TABLE table_name DROP INDEX index_name

SQL DROP TABLE 语句
DROP TABLE 语句用于删除表（表的结构、属性以及索引也会被删除）：
DROP TABLE 表名称

SQL DROP DATABASE 语句
DROP DATABASE 语句用于删除数据库：
DROP DATABASE 数据库名称

SQL TRUNCATE TABLE 语句
如果我们仅仅需要除去表内的数据，但并不删除表本身，那么我们该如何做呢？
请使用 TRUNCATE TABLE 命令（仅仅删除表格中的数据）：
TRUNCATE TABLE 表名称
## ALTER TABLE 语句
ALTER TABLE 语句
ALTER TABLE 语句用于在已有的表中添加、修改或删除列。

SQL ALTER TABLE 语法
如需在表中添加列，请使用下列语法:

ALTER TABLE table_name
ADD column_name datatype

要删除表中的列，请使用下列语法：

ALTER TABLE table_name 
DROP COLUMN column_name
注释：某些数据库系统不允许这种在数据库表中删除列的方式 (DROP COLUMN column_name)。

要改变表中列的数据类型，请使用下列语法：

ALTER TABLE table_name
ALTER COLUMN column_name datatype

# VIEW（视图）
在 SQL 中，视图是基于 SQL 语句的结果集的可视化的表。

视图包含行和列，就像一个真实的表。视图中的字段就是来自一个或多个数据库中的真实的表中的字段。我们可以向视图添加 SQL 函数、WHERE 以及 JOIN 语句，我们也可以提交数据，就像这些来自于某个单一的表。

注释：数据库的设计和结构不会受到视图中的函数、where 或 join 语句的影响。

SQL CREATE VIEW 语法
    CREATE VIEW view_name AS
    SELECT column_name(s)
    FROM table_name
    WHERE condition

SQL CREATE VIEW 实例
可以从某个查询内部、某个存储过程内部，或者从另一个视图内部来使用视图。通过向视图添加函数、join 等等，我们可以向用户精确地提交我们希望提交的数据。

样本数据库 Northwind 拥有一些被默认安装的视图。视图 "Current Product List" 会从 Products 表列出所有正在使用的产品。这个视图使用下列 SQL 创建：

CREATE VIEW [Current Product List] AS
SELECT ProductID,ProductName
FROM Products
WHERE Discontinued=No
我们可以查询上面这个视图：

SELECT * FROM [Current Product List]
Northwind 样本数据库的另一个视图会选取 Products 表中所有单位价格高于平均单位价格的产品：

CREATE VIEW [Products Above Average Price] AS
SELECT ProductName,UnitPrice
FROM Products
WHERE UnitPrice>(SELECT AVG(UnitPrice) FROM Products) 
我们可以像这样查询上面这个视图：

SELECT * FROM [Products Above Average Price]
另一个来自 Northwind 数据库的视图实例会计算在 1997 年每个种类的销售总数。请注意，这个视图会从另一个名为 "Product Sales for 1997" 的视图那里选取数据：

CREATE VIEW [Category Sales For 1997] AS
SELECT DISTINCT CategoryName,Sum(ProductSales) AS CategorySales
FROM [Product Sales for 1997]
GROUP BY CategoryName 
我们可以像这样查询上面这个视图：

SELECT * FROM [Category Sales For 1997]
我们也可以向查询添加条件。现在，我们仅仅需要查看 "Beverages" 类的全部销量：

SELECT * FROM [Category Sales For 1997]
WHERE CategoryName='Beverages'
SQL 更新视图
您可以使用下面的语法来更新视图：

SQL CREATE OR REPLACE VIEW Syntax
CREATE OR REPLACE VIEW view_name AS
SELECT column_name(s)
FROM table_name
WHERE condition
现在，我们希望向 "Current Product List" 视图添加 "Category" 列。我们将通过下列 SQL 更新视图：

CREATE VIEW [Current Product List] AS
SELECT ProductID,ProductName,Category
FROM Products
WHERE Discontinued=No
SQL 撤销视图
您可以通过 DROP VIEW 命令来删除视图。

SQL DROP VIEW Syntax
DROP VIEW view_name
