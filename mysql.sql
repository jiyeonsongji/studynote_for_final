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
  FROM 테이블,      -- 어느 테이블에서
WHERE 조건,        -- 어떤 조건으로
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

-- 숫자형 함수
-- ABS(-5) -> 5 (절대값)
-- ROUND(1153.456, 1) -> 1153.5 (반올림, 소수 1자리)
-- ROUND(1153.456, -1) -> 1150 (반올림, 일의 자리)
