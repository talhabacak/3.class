CREATE TABLE IF NOT EXISTS SEEKERS (
	tckn VARCHAR(12) PRIMARY KEY,
	fname VARCHAR(50) NOT NULL,
	lname VARCHAR(50) NOT NULL,
	gender CHAR,
	expected_salary INT CHECK (expected_salary > 0),
	dob DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS COMPANIES (
	vkn VARCHAR(12) PRIMARY KEY,
	name VARCHAR(50) NOT NULL,
	description VARCHAR(250) NOT NULL,
	location text[],
	post_count INT DEFAULT 0 NOT NULL
);

CREATE TABLE IF NOT EXISTS POSTINGS (
	id INT PRIMARY KEY,
	position VARCHAR(100),
	status VARCHAR(6) DEFAULT 'open' NOT NULL,
	company_vkn VARCHAR(12) NOT NULL,
	min_salary INT NOT NULL CHECK (min_salary > 0),
	max_salary INT NOT NULL,
	opening_date DATE,
	closing_date DATE,
	FOREIGN KEY(company_vkn) REFERENCES COMPANIES(vkn)
);

CREATE TABLE IF NOT EXISTS APPLICATIONS (
	id INT PRIMARY KEY,
	seeker_tckn VARCHAR(12) NOT NULL,
	posting_id INT NOT NULL,
	application_date DATE DEFAULT CURRENT_DATE NOT NULL,
	hired CHAR DEFAULT 0 NOT NULL,
	CONSTRAINT fk_seeker
		FOREIGN KEY(seeker_tckn) 
		REFERENCES SEEKERS(tckn)
		ON DELETE CASCADE,
	CONSTRAINT fk_posting
		FOREIGN KEY(posting_id) 
		REFERENCES POSTINGS(id)
		ON DELETE NO ACTION
);

CREATE SEQUENCE IF NOT EXISTS SEQ_POSTING_ID
START WITH 1 INCREMENT BY 1 NO CYCLE;

CREATE SEQUENCE IF NOT EXISTS SEQ_APPLICATION_ID
START WITH 1 INCREMENT BY 1 NO CYCLE;

INSERT INTO COMPANIES VALUES 
('7017438581', 'Samsung','Dünya''nın en büyük teknoloji şirketi olma yolunda ilerlemektedir.',					'{"Istanbul", "Ankara", "Izmir", "Aydin"}'),
('3018532388', 'Turkcell','Türkiye''nin en büyük telekomünikasyon şirketidir.', 								'{"Istanbul", "Izmir"}'),
('4291657945', 'Kuveyt Türk Katılım Bankası','Katılım bankaları arasında 1., tüm bankalar arasında 10.dur', 	'{"Istanbul", "Ankara", "Izmir"}'),
('8049007111', 'Garanti Teknoloji','Türkiye''nin ilk 3 bankası içine girme hedefi bulunmaktadır.', 				'{"Istanbul", "Izmir", "Bursa"}'),
('9999248558', 'Trendyol','Türkiye''nin değil dünyanın en iyi e-ticaret şirketi olma yolunda ilerlemektedir.',	'{"Istanbul", "Ankara", "Izmir", "Bursa"}'),
('3225281796', 'Netaş','Telefon network hizmetlerinde Türkiye''nin köklü markasıdır.', 							'{"Istanbul", "Ankara", "Izmir", "Bursa"}'),
('2066039019', 'Turkcell Global Bilgi','Turkcell''in alt kuruluşudur. Online ödeme hizmetleri vermektedir.', 	'{"Istanbul", "Adana", "Aydin", "Bursa"}'),
('2414000980', 'Akbank','Türkiye''nin en fazla aktif müşteriye sahip bankasıdır.', 								'{"Istanbul", "Ankara", "Adana", "Aydin", "Bursa"}'),
('3736925410', 'THY','Ülkemizi temsil eden dünyaın en iyi havayolu şirketlerindendir.', 						'{"Istanbul", "Ankara", "Adana", "Aydin", "Bursa"}'),
('4710261098', 'Mercedes Benz','Türkiye''de İstanbul''da ve Aksaray''da hizmet vermektedir.', 					'{"Istanbul", "Adana", "Aydin", "Bursa"}'),
('7421803526', 'Hepsiburada','E-ticaret sektörünü bir adım öteye taşımayı hedef edinmiştir.', 					'{"Ankara", "Izmir", "Adana", "Aydin"}'),
('3276892154', 'NCR','Dünyanın en iyi finansal hizmet teknolojilerini üreten firmasıdır.', 						'{"Ankara", "Izmir", "Adana", "Aydin"}'),
('3247717522', 'Ziraat Bankası','Türkiye''nin son 100 yıldır en iyi bankası konumundadır.', 					'{"Istanbul", "Adana", "Aydin"}'),
('6680288285', 'Aselsan','Geliştirdiği savunma teknolojileriyle Türkiye''nin aydınlık geleceğidir.', 			'{"Istanbul", "Ankara", "Izmir", "Adana", "Aydin"}'),
('1949942318', 'Tüpraş','Türkiye''nin en çok kar eden şirketidir.', 											'{"Ankara", "Adana", "Aydın", "Bursa"}');

INSERT INTO SEEKERS VALUES 
('13810608984', 'Aydın',	'Sancak',	'E', 2500, 	'01-05-1983'),
('34552736780', 'Saffet',	'Bayrak',	'E', 3600, 	'10-11-1987'),
('55447684306', 'Türkan',	'Gürsoy',	'K', 2570, 	'10-26-1989'),
('84795448964', 'Canan',	'Ersoy',	'K', 5500, 	'07-07-1995'),
('83752123944', 'İzzet',	'Birden',	'E',12000, 	'04-06-1996'),
('68311147708', 'Can',		'Arat',		'E', 1750, 	'11-05-1999'),
('43013920552', 'Aydın', 	'Oral',		'E', 12500, '12-12-1984'),
('40445977628', 'Kemal', 	'Mutlu', 	'E', 5200, 	'06-12-1975'),
('68198602000', 'Zeynep', 	'Yılmaz', 	'K', 3500, 	'07-25-1988'),
('71080755272', 'Ali', 		'Yılmaz', 	'E', 4500, 	'02-24-1990'),
('56179376644', 'Mehmet', 	'Can', 		'E', 6000, 	'01-17-1991'),
('79691224606', 'Kamil', 	'Erdem', 	'E', 7000, 	'12-12-1992'),
('96637756762', 'Tufan', 	'Ersoy', 	'E', 5500, 	'12-10-1995'),
('13044886554', 'Naz', 		'Soylu', 	'K', 9000, 	'04-30-1983'),
('36576584644', 'Aydın', 	'Ertepe', 	'E', 10000, '04-28-1984'),
('83768057554', 'İclal', 	'Can', 		'K', 5250, 	'11-24-1991'),
('38934400696', 'Damla', 	'Mutlu', 	'K', 12500, '01-08-1978'),
('10327192432', 'Ahmet', 	'Yılmaz', 	'E', 6500, 	'03-09-1994'),
('87344897336', 'Ahmet', 	'Kaptan', 	'E', 7500, 	'09-01-1993');

INSERT INTO POSTINGS VALUES 
(nextval('SEQ_POSTING_ID'), 'Veritabanı Uzmanı', 	'open', 	'7017438581',	5000,	10000,	'01-03-2020', '01-01-2021'),
(nextval('SEQ_POSTING_ID'), 'İş Analisti', 			'closed',	'4291657945',	7000,	10000,	'10-26-2019', '12-12-2019'),
(nextval('SEQ_POSTING_ID'), 'Endüstri Mühendisi', 	'open', 	'6680288285',	3000,	11000,	'10-11-2019', '11-06-2021'),
(nextval('SEQ_POSTING_ID'), 'Sistem Analisti', 		'open', 	'9999248558',	7000,	10000,	'05-10-2019', '02-24-2021'),
(nextval('SEQ_POSTING_ID'), 'İş Analisti', 			'open', 	'9999248558',	7000,	10000,	'07-04-2020', '06-02-2021'),
(nextval('SEQ_POSTING_ID'), 'Operasyon Yöneticisi',	'open',		'3736925410',	7000,	12000,	'02-01-2019', '12-08-2021'),
(nextval('SEQ_POSTING_ID'), 'Yazılım Mühendisi', 	'closed',	'3018532388',	6500,	10000,	'03-07-2019', '10-07-2019'),
(nextval('SEQ_POSTING_ID'), 'İş Analisti', 			'open',		'7017438581',	10000,	15000,	'10-05-2020', '04-11-2021'),
(nextval('SEQ_POSTING_ID'), 'Risk Uzmanı', 			'closed', 	'2414000980',	6500,	7000,	'12-26-2019', '07-29-2019'),
(nextval('SEQ_POSTING_ID'), 'Yazılım Mühendisi', 	'closed', 	'3225281796',	12000,	15000,	'11-07-2019', '01-01-2020'),
(nextval('SEQ_POSTING_ID'), 'Scrum Master', 		'open',		'1949942318',	5000,	7500,	'05-10-2019', '02-24-2021'),
(nextval('SEQ_POSTING_ID'), 'Test Uzmanı',			'open',		'2066039019',	6000,	8000,	'05-23-2020', '09-01-2021'),
(nextval('SEQ_POSTING_ID'), 'Veritabanı Uzmanı', 	'open',		'7421803526',	12000,	15000,	'04-21-2019', '10-03-2021');

INSERT INTO APPLICATIONS VALUES 
(nextval('SEQ_APPLICATION_ID'), '83752123944', 	2, 	'12-12-2019', 1),
(nextval('SEQ_APPLICATION_ID'), '96637756762', 	1, 	'01-03-2020', 0),
(nextval('SEQ_APPLICATION_ID'), '96637756762', 	13, '01-03-2020', 0),
(nextval('SEQ_APPLICATION_ID'), '56179376644', 	7, 	'10-07-2019', 1),
(nextval('SEQ_APPLICATION_ID'), '38934400696', 	10, '01-01-2020', 1),
(nextval('SEQ_APPLICATION_ID'), '87344897336', 	2, 	'12-12-2019', 0),
(nextval('SEQ_APPLICATION_ID'), '87344897336', 	9, 	'07-29-2019', 1),
(nextval('SEQ_APPLICATION_ID'), '40445977628', 	1, 	'01-03-2020', 0),
(nextval('SEQ_APPLICATION_ID'), '40445977628', 	11, '01-03-2020', 0),
(nextval('SEQ_APPLICATION_ID'), '68198602000', 	4, 	'07-04-2020', 0),
(nextval('SEQ_APPLICATION_ID'), '84795448964', 	5, 	'07-04-2020', 0);

--Arayuzden insert, update, delete (4. madde)
INSERT INTO SEEKERS VALUES 
('79266970006', 'Can', 		'Eryürür', 	'E', 2400, 	'12-02-1983');
UPDATE SEEKERS SET dob = '03-03-1993' WHERE tckn = '79266970006';
DELETE FROM SEEKERS WHERE tckn = '79266970006';

--Arayuzden age parametresi ile filtrelenebilir. (5. ve 6. madde)
CREATE OR REPLACE VIEW SEEKERS_AGE AS
SELECT tckn,
		CONCAT(fname, ' ', lname) AS name,
		expected_salary,
		CAST(DATE_PART('YEAR', AGE(dob)) AS INT) AS age
FROM SEEKERS;

--Intersect kullanilarak, yasi 30dan buyuk, maas beklentisi 12500'den az ve bir is basvurusu yapmis kisiler.
--(8. madde)
SELECT * FROM SEEKERS_AGE WHERE AGE > 30 AND expected_salary < 12500
INTERSECT
SELECT * FROM SEEKERS_AGE WHERE tckn IN (SELECT seeker_tckn FROM APPLICATIONS);

--1'den fazla is ilani paylasmis olan sirketler (9. madde)
SELECT tbl2.name,
		tbl1.posting_count
FROM (
	SELECT company_vkn, 
			COUNT(*) AS posting_count 
	FROM POSTINGS
	GROUP BY company_vkn
	HAVING COUNT(*) > 1
) tbl1
INNER JOIN COMPANIES tbl2
ON tbl1.company_vkn = tbl2.vkn;

--1. Trigger (11. Madde)
CREATE OR REPLACE FUNCTION CHECK_AGE() RETURNS trigger AS $CHECK_AGE$
    BEGIN
		RAISE INFO 'CHECK_AGE function is triggered';
        IF CAST(DATE_PART('YEAR', AGE(NEW.dob)) AS INT) < 18 THEN
            RAISE EXCEPTION 'Children under the age of 18 cannot register to the system';
        END IF;

        RETURN NEW;
    END;
$CHECK_AGE$ LANGUAGE plpgsql;

CREATE TRIGGER CHECK_AGE BEFORE INSERT OR UPDATE ON SEEKERS
    FOR EACH ROW EXECUTE PROCEDURE CHECK_AGE();

--Triggeri arayuzden tetiklemek icin SEEKERS tablosuna yeni bir kayit eklenebilir
INSERT INTO SEEKERS VALUES 
('79266970008', 'Can', 	'Eryürür', 	'E', 2400, 	'12-02-2009');

--Trigger'i eklemeden COMPANIES tablosundaki post_count alaninin hesaplanmasi
UPDATE COMPANIES
SET post_count = tbl2.cnt
FROM (SELECT company_vkn, COUNT(*) AS cnt FROM POSTINGS GROUP BY company_vkn) tbl2
WHERE vkn = tbl2.company_vkn;

--2. Trigger (11. Madde)
CREATE OR REPLACE FUNCTION CALC_POST_COUNT() RETURNS TRIGGER AS $POST_COUNT$
    BEGIN
		RAISE INFO 'calc_post_count function is triggered';
        IF (TG_OP = 'DELETE') THEN
			UPDATE COMPANIES SET post_count = post_count -1 WHERE vkn = OLD.company_vkn;
        ELSIF (TG_OP = 'UPDATE') THEN
			UPDATE COMPANIES SET post_count = post_count -1 WHERE vkn = OLD.company_vkn;
			UPDATE COMPANIES SET post_count = post_count +1 WHERE vkn = NEW.company_vkn;
        ELSIF (TG_OP = 'INSERT') THEN
			UPDATE COMPANIES SET post_count = post_count +1 WHERE vkn = NEW.company_vkn;
        END IF;
        RETURN NULL;
    END;
$POST_COUNT$ LANGUAGE plpgsql;

CREATE TRIGGER POST_COUNT
AFTER INSERT OR UPDATE OR DELETE ON POSTINGS
    FOR EACH ROW EXECUTE PROCEDURE CALC_POST_COUNT();
	
--Triggeri arayuzden tetiklemek icin POSTINGS tablosu update edilebilir.
UPDATE POSTINGS SET company_vkn = '3736925410' WHERE company_vkn = '9999248558';

--1. Fonksyion (10. Madde)
--Seekers tablosunda verilen parametre kadar zam yapar ve yeni sonuclari dondurur.
CREATE OR REPLACE FUNCTION raise_expected_salary(percentage INT)
RETURNS TABLE (
	fname VARCHAR(50),
	lname VARCHAR(50),
	raised_expected_salary INT,
	dob DATE
) 
AS $$
BEGIN
	IF (percentage > 0) THEN
		--First update table
		UPDATE SEEKERS SET expected_salary = expected_salary * (100 + percentage) / 100;
		--Then return it
		RETURN QUERY
			SELECT
				tbl1.fname,
				tbl1.lname,
				tbl1.expected_salary AS raised_expected_salary,
				tbl1.dob
			FROM
				SEEKERS tbl1;
	ELSE
		RAISE EXCEPTION 'Percantage must be higher than 0';
	END IF;
END;
$$ LANGUAGE PLPGSQL;

SELECT raise_expected_salary(20);

--2. Fonksyion (10. Madde)
--Hangi firmalarin parametre olarak verilen sayidan daha fazla ilde ofisi oldugunu dondurur.
CREATE OR REPLACE FUNCTION find_companies(count INT)
RETURNS SETOF VARCHAR
AS $$
BEGIN
	IF (count IS NOT NULL) THEN
		RETURN QUERY
			SELECT name
			FROM COMPANIES 
			WHERE array_length(location, 1) > count;
	ELSE
		RAISE EXCEPTION 'city cant be null';
	END IF;
END;
$$ LANGUAGE PLPGSQL;

SELECT find_companies(4);

--3. Fonksyion (10. Madde)
--Parametre olarak verilen pozisyondaki maksimum maasi dondurur.
CREATE OR REPLACE FUNCTION find_max_salary_by_position(job_position VARCHAR, OUT max_salary INT)
AS $$
BEGIN
	IF (job_position IS NOT NULL) THEN
			SELECT MAX(tbl1.max_salary) INTO max_salary
			FROM POSTINGS tbl1
			WHERE upper(tbl1.position) = upper(job_position);
	ELSE
		RAISE EXCEPTION 'position cant be null';
	END IF;
END;
$$ LANGUAGE PLPGSQL;

SELECT find_max_salary_by_position('Veritabanı Uzmanı');