-- # 1번 문제 #
-- 별칭을 지정할때는 병칭은 컬럼 명 바로 뒤에 별명을 정의하여야 하며, 
-- 컬럼 명과 별명 사이의 키워드 AS는 써도 되고 안 써도 된다.
-- 만약 빈 칸 또는 특수 문자가 있거나 대소문자를 구별한다면, “ ”가 필요하다.
-- 또한 연산은 X를 사용하지 않고 *를 사용하며, 실제 테이블의 열의 명칭과 일치해야한다.
SELECT employee_id, last_name sal x 12 ANNUAL SALARY (X)
SELECT employee_id as "last_name" , salary*12 "ANNUAL SALARY" (O)

FROM HR.employees;

-- # 2번 문제 #
select * -- 모두 선택한다는 의미이다.
from HR.departments;

-- # 3번 문제 #
--      사원 번호,  사원 이름,   사원이름,   업무코드, 입사일 -> 별칭STARTDATE
select employee_id, first_name, last_name, job_id, hire_date as STARTDATE
from HR.employees;

-- # 4번 문제 #
-- 2개 열을 하나의 셀로 뭉치고 ,로 이어줌 // 해당 이름은 대문자 및 and라는 연산자가 있기 때문에 "로 묶음
SELECT first_name || ', ' || job_id  as "Employee and Title"
FROM HR.employees;


-- ###########
-- ###########
-- # 2번 과제 # 
-- ###########
-- ###########

-- # 1번 문제 #
select first_name, salary
FROM HR.employees
-- 12000달러를 넘은 연봉의 사람에 대한 조건문
where salary > 12000;

-- # 2번 문제 #
select first_name, department_id
from HR.employees
-- 사원 번호가 176인 조건이기 때문에 employee_id = 176
where employee_id = 176;

-- # 3번 문제 #
select first_name, salary 
from HR.employees
-- 급여가 해당 5000보다 작고 12000보다 크다면 해당 범위에 적용되지 안는 것임
where salary <  5000 and 12000 > salary;

-- # 4번 문제 #
SELECT first_name, salary, department_id
FROM HR.employees
-- 여러 개의 조건문에 대해서는 괄호로 범위를 지정한다. 그리고 and와 or로 공통된 것인지 아닌 지 결정한다.
WHERE (salary >= 5000 AND salary <= 12000) AND (department_id = 20 OR department_id = 50)
-- 오름차순으로 정렬하기 위해서 해당 코드를 작성한다.
ORDER BY salary;

-- # 5번 문제 #
select first_name, department_id
from HR.employees
where department_id = 20 or department_id = 50
-- 이름을 기준으로 정렬
order by first_name;

-- # 6번 문제 #
-- 이름을 지정하기 위해서 ""와 as를 사용해서 지정함.
select first_name as "Employee", salary as "Monthly Salary"
from HR.employees
where (salary >= 5000 and salary <= 12000) and (department_id = 50 or department_id = 20);

-- # 7번 문제 #
select first_name, department_id
from HR.employees
-- 정보가 없음을 나타내는 것은 = NULL이 아닌 is NULL이다.
where manager_id is NULL;

-- # 8번 문제 #
SELECT first_name, salary, commission_pct
FROM HR.employees
-- IS NOT NULL은 널이 아니다~ 라는 것을 의미함.
WHERE commission_pct IS NOT NULL
-- 기존 오름차순과 반대로 DESC 작성함으로 내림차순으로 정렬됨
ORDER BY salary DESC, commission_pct DESC;

-- # 9번 문제 #
select first_name
from HR.employees
-- 3번째 문자가 a여야 하기 때문에 a앞에는 무조건 2개의 문자가 와야하고
-- 뒤에는 몇 개의 문자가 오든 상관없다.
where first_name like '__a%';

-- # 10번 문제 #
select first_name
from HR.employees
-- a와 e의 앞 뒤로 %를 통해서 묶었기 때문에 해당 조건문은 a, e가 어디 있든지
-- 존재만 한다면 된다. 
where first_name like '%a%' and first_name like '%e%';

-- # 11번 문제 #
-- 이름과 월급은 employees 테이블에 있지만 job_title은 employee 테이블에 없다.
-- 때문에 jobs 테이블에서 가져온다.
select e.first_name, j.job_title, e.salary
-- employees 테이블에서 가져온 것들은 e라고 한다
from HR.employees e
-- jobs테이블에 job_title을 가져오기 위해 employees 테이블과 jobs 테이블을 결합한다.
join HR.jobs j on e.job_id = j.job_id
where (j.job_id = 'SA_REP' or j.job_id = 'ST_CLERK') and e.salary not in (2500, 3500, 7000);

-- # 12번 문제 #
select first_name, salary, commission_pct
from HR.employees
-- 커미션 비율이 0.2퍼센트라는 조건문
where commission_pct = 0.2;