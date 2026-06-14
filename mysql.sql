-- 데이터 베이스와 테이블 생성

-- 생성
CREATE DATABASE mywork;
CREATE SCHEMA IF NOT EXISTS mywork;  -- IF NOT EXISTS: 이미 있어도 에러 안 남

-- 삭제
DROP DATABASE mywork;
DROP SCHEMA IF EXISTS mywork;

-- 진입 (사용)
USE mywork;

-- 테이블 생성
CREATE TABLE highschool_students (
  student_no VARCHAR(20) NOT NULL,
  student_name VARCHAR(100) NOT NULL,
  grade TINYINT NULL,
  class VARCHAR(50) NULL,
  gender VARCHAR(20) NULL,
  age SMALLINT NULL,
  enter_date DATE
  );

-- 구조 확인 
DESC highschool_students;

-- 삭제
DROP TABLE highschool_students;

-- 기본키 생성 방법
-- 1: 컬럼 옆에 바로 생성
student_no VARCHAR(20) NOT NULL PRIMARY KEY,
-- 2: 테이블 맨 아래 선언
[CONSTRAINT] PRIMARY KEY (student_no)
-- 3: 테이블 생성 후 추가
ALTER TABLE highschool_students
ADD PRIMARY KEY(student_no);

-- SELECT 기본 구조
SELECT 칼럼1, 칼럼2  -- 어떤 칼럼을
FROM 테이블     -- 어느 테이블에서
WHERE 조건        -- 어떤 조건으로
ORDER BY 칼럼 ASC/DESC  -- 어떻게 정렬
LIMIT n;               -- 몇 개만 조회
-- 실행 순서: FROM -> WHERE -> SELECT -> ORDER BY, LIMIT

-- 2012년 제작, 2019년 개봉 영화 조회
SELECT * FROM box_office
WHERE years = 2012
AND release_date BETWEEN '2019-01-01' AND '2019-12-31';

-- 한국 도시를 이름 오름차순, 인구 내림차순으로 5건만 조회
USE world;
SELECT * FROM city
WHERE countrycode = 'KOR'
ORDER BY name ASC, population DESC
LIMIT 5; 

-- GROUP BY 기본 구조
SELECT 칼럼1, 집계함수(칼럼2),
FROM 테이블
WHERE 조건
GROUP BY 칼럼1
ORDER BY 칼럼1;

-- 대륙별로 데이터 묶기
SELECT continent
FROM country
GROUP BY continent;

-- 칼럼 순번으로 쓰는 것도 가능
SELECT continent, region
FROM country
GROUP BY 1, 2
ORDER BY 1,2;   -- (1 = continent, 2 = region)

-- 문자형 함수도 쓸 수 있음
SELECT SUBSTRING(district, 1, 2) AS 도명
FROM city
WHERE countrycode = 'KOR'
GROUP BY SUBSTRING(district, 1, 2) -- 앞의 두 글자가 같으면 같은 지역(그룹)으로 취급
ORDER BY 1;

-- DISTINCT 중복 제거: GROUP BY 없이도 중복을 제거하고 고유한 값을 뽑을 때 사용
-- 대륙 종류만 뽑기 (중복제거)
SELECT DISTINCT continent
FROM country;

-- GROUP BY로 같은 결과를 낼 수 있음 (집계함수가 없어서)
SELECT continent
FROM country
GROUP BY continent;


-- GROUP BY + 집계 함수 조합 예시
-- 2019년 개봉 영화를 유형별로 묶어서 최대/최소/전체 매출 집계
SELECT movie_type,
       MAX(sale_amt) AS 최대매출,
       MIN(sale_amt) AS 최소매출,
       SUM(sale_amt) AS 전체매출
FROM box_office
WHERE YEAR(release_date) = 2019
GROUP BY movie_type;

-- 연도별 개봉 영화 편수
SELECT YEAR(release_date) release_year, COUNT(*)
 FROM box_office
GROUP BY YEAR(release_date)
ORDER BY 1 DESC;

-- WITH ROLLUP: GROUP BY 뒤에 WITH ROLLUP을 붙이면 항목별 합계 + 전체 총계 행 자동 추가
SELECT movie_type, SUM(sale_amt) AS 매출합계
FROM box_office
WHERE YEAR(release_date) = 2019
GROUP BY movie_type WITH ROLLUP;

-- GROUPING() 함수: WITH ROLLUP과 함께 써서 어느 행이 총계 행인지 구분 가능
SELECT movie_type, SUM(sale_amt) AS 매출합계, GROUPING(movie_type) AS 총계여부
FROM box_office
WHERE YEAR(release_date) = 2019
GROUP BY movie_type WITH ROLLUP;

-- HAVING절: 집계 결과에 조건 걸기
-- 2019년 영화 중 유형별 총 매출이 1억 이상인 것만 조회
SELECT movie_type, SUM(sale_amt) AS 총매출
FROM box_office
WHERE YEAR(release_date) = 2019
GROUP BY movie_type
HAVING SUM(sale_amt) >= 100000000
ORDER BY 총매출 DESC;

-- Join: 테이블끼리 관계 맺기 (두 테이블에 공통으로 있는 칼럼을 연결고리 삼아 한 번에 조회하는 것)
-- Join 기본 구조
SELECT 
      별칭1.칼럼명,
      별칭2.칼럼명
FROM
    테이블1 AS 별칭1
    JOIN 테이블2 AS 별칭2
      ON 별칭1.칼럼명 = 별칭2.칼럼명;

-- 예시
SELECT 
    e.name, 
    d.dept_name
FROM 
    employees AS e
    JOIN departments AS d
      ON e.dept_no = d.dept_no;
-- 컴퓨터는 FROM -> ON -> SELECT 순서로 처리함

-- INNER JOIN: 교집합 조인
-- 방법 1: INNER JOIN + ON 절 (권장)
SELECT a.name, a.continent, b.name AS 도시명
FROM country a
INNER JOIN city b
ON a.code = b.countrycode
WHERE a.continent = 'Asia';

-- 방법 2: FROM에 쉼표, WHERE에 조인 조건 (구식이지만 결과는 동일)
SELECT a.Name, b.Name AS 도시명
FROM country a, city b
WHERE a.Code = b.CountryCode
AND a.Continent = 'Asia';

-- OUTER JOIN: 한쪽 데이터는 무조건 포함
-- LEFT JOIN: FROM 절 왼쪽(첫번째) 테이블 기준 - 왼쪽 테이블은 전부 나옴
-- country(왼쪽) 기준: 도시가 없는 나라도 포함
SELECT a.Name AS 나라, b.Name AS 도시
FROM country a
LEFT JOIN city b
ON a.Code = b.CountryCode;
-- 도시가 없는 나라는 도시 칼럼이 NULL로 표시됨

-- RIGHT JOIN: FROM 절 오른쪽(두번째) 테이블 기준 - 오른쪽 테이블은 전부 나옴
SELECT a.Name AS 나라, b.Name AS 도시
FROM country a
RIGHT JOIN city b
ON a.Code = b.CountryCode;



