drop table "FARM" cascade constraints;
drop table "ANIMAL" cascade constraints;
drop table "EMPLOYEE" cascade constraints;
drop table "PRODUCT" cascade constraints;
drop table "CUSTOMER" cascade constraints;
drop table "PRODUCT_SALE" cascade constraints;
drop table "ANIMAL_CARE" cascade constraints;
drop table "FEED" cascade constraints;
drop table "ANIMAL_FEED" cascade constraints;
drop table "SUPPLIER" cascade constraints;
drop table "FEED_SUPPLY" cascade constraints;

drop view "AVERAGE_ANIMAL_AGE_BY_SPECIES" cascade constraints;
drop view "ANIMAL_HEALTH_SUMMARY" cascade constraints;
drop view "PRODUCT_SALES_DETAILS" cascade constraints;
drop view "ANIMAL_AND_FEED_USAGE" cascade constraints;
drop view "ANIMALS_WITH_CARE_INFO" cascade constraints;
drop view "EMPLOYEE_CARE_COUNT" cascade constraints;
drop view "MONTHLY_SALES_SUMMARY" cascade constraints;
drop view "ANIMALS_FED_OR_CARED_BUT_NOT_BOTH" cascade constraints;
drop view "ANIMALS_WITH_ABOVE_AVERAGE_FEED" cascade constraints;
drop view "ANIMALS_NOT_CARED_BY_EMPLOYEE_1" cascade constraints;

BEGIN
    EXECUTE IMMEDIATE 'DROP SEQUENCE seq_primary_keys';
EXCEPTION
    WHEN OTHERS THEN
        -- ORA-02289: sequence does not exist
        IF SQLCODE != -2289 THEN
            RAISE;
        END IF;
END;
/

CREATE TABLE Farm (
farm_id INT PRIMARY KEY,
name VARCHAR(100),
location VARCHAR(255)
);

CREATE TABLE Animal (
animal_id INT PRIMARY KEY,
species VARCHAR(50),
age INT,
health_status VARCHAR(100)
);

CREATE TABLE Employee(
employee_id INT PRIMARY KEY,
name VARCHAR(100),
position VARCHAR(50)
);

CREATE TABLE Product(
product_id INT PRIMARY KEY,
name VARCHAR(100),
price DECIMAL(10,2),
quantity INT
);

CREATE TABLE Customer(
customer_id INT PRIMARY KEY,
name VARCHAR(100),
contact_info VARCHAR(255)
);

CREATE TABLE Product_Sale(
product_id INT,
customer_id INT,
sale_date DATE,
quantity INT,
total_price DECIMAL(10,2),
PRIMARY KEY(product_id,customer_id),
FOREIGN KEY(product_id) REFERENCES Product(product_id),
FOREIGN KEY(customer_id) REFERENCES Customer(customer_id)
);

CREATE TABLE Animal_care(
animal_id INT,
employee_id INT,
care_date DATE,
care_type VARCHAR(100),
PRIMARY KEY(animal_id,employee_id),
FOREIGN KEY(animal_id) REFERENCES Animal(animal_id),
FOREIGN KEY(employee_id) REFERENCES Employee(employee_id)
);

CREATE TABLE Feed(
feed_id INT PRIMARY KEY,
name VARCHAR(100),
stock_quanitity INT
);

CREATE TABLE Animal_Feed(
animal_id INT,
feed_id INT,
feed_date DATE,
amount INT,
PRIMARY KEY(animal_id, feed_id),
FOREIGN KEY(animal_id) REFERENCES Animal(animal_id),
FOREIGN KEY(feed_id) REFERENCES Feed(feed_id)
);

CREATE TABLE Supplier(
supplier_id INT PRIMARY KEY,
name VARCHAR(100),
contact_info VARCHAR(255)
);

CREATE TABLE Feed_Supply(
feed_id INT,
supplier_id INT,
supply_date DATE,
quantity INT,
PRIMARY KEY(feed_id, supplier_id),
FOREIGN KEY(feed_id) REFERENCES Feed(feed_id),
FOREIGN KEY(supplier_id) REFERENCES Supplier(supplier_id)
);

INSERT INTO Farm VALUES (1, 'Green Farm', 'Slovakia, Košice');
INSERT INTO Farm VALUES (2, 'Sunny Hills', 'Slovakia, Prešov');
INSERT INTO Farm VALUES (3, 'Happy Cows', 'Slovakia, Nitra');
INSERT INTO Farm VALUES (4, 'Eco Fields', 'Slovakia, Žilina');
INSERT INTO Farm VALUES (5, 'River Side', 'Slovakia, Bratislava');
INSERT INTO Farm VALUES (6, 'Mountain Farm', 'Slovakia, Poprad');
INSERT INTO Farm VALUES (7, 'Valley View', 'Slovakia, Trnava');
INSERT INTO Farm VALUES (8, 'Golden Meadow', 'Slovakia, Banská Bystrica');
INSERT INTO Farm VALUES (9, 'Nature Nest', 'Slovakia, Trenčín');
INSERT INTO Farm VALUES (10, 'AgroFarm', 'Slovakia, Levice');

INSERT INTO Animal VALUES (1, 'Cow', 5, 'Healthy');
INSERT INTO Animal VALUES (2, 'Pig', 2, 'Sick');
INSERT INTO Animal VALUES (3, 'Sheep', 3, 'Healthy');
INSERT INTO Animal VALUES (4, 'Chicken', 1, 'Healthy');
INSERT INTO Animal VALUES (5, 'Goat', 4, 'Injured');
INSERT INTO Animal VALUES (6, 'Cow', 6, 'Healthy');
INSERT INTO Animal VALUES (7, 'Pig', 1, 'Healthy');
INSERT INTO Animal VALUES (8, 'Horse', 8, 'Sick');
INSERT INTO Animal VALUES (9, 'Duck', 2, 'Healthy');
INSERT INTO Animal VALUES (10, 'Cow', 7, 'Injured');

INSERT INTO Employee VALUES (1, 'Ján Kováč', 'Veterinarian');
INSERT INTO Employee VALUES (2, 'Eva Nováková', 'Feeder');
INSERT INTO Employee VALUES (3, 'Marek Horváth', 'Cleaner');
INSERT INTO Employee VALUES (4, 'Lucia Bieliková', 'Supervisor');
INSERT INTO Employee VALUES (5, 'Tomáš Varga', 'Feeder');
INSERT INTO Employee VALUES (6, 'Michaela Urbanová', 'Manager');
INSERT INTO Employee VALUES (7, 'Peter Hruška', 'Veterinarian');
INSERT INTO Employee VALUES (8, 'Kristína Tóthová', 'Feeder');
INSERT INTO Employee VALUES (9, 'Roman Farkaš', 'Cleaner');
INSERT INTO Employee VALUES (10, 'Zuzana Sýkorová', 'Supervisor');

INSERT INTO Product VALUES (1, 'Milk', 1.50, 100);
INSERT INTO Product VALUES (2, 'Eggs', 2.00, 200);
INSERT INTO Product VALUES (3, 'Cheese', 4.00, 50);
INSERT INTO Product VALUES (4, 'Meat', 5.50, 70);
INSERT INTO Product VALUES (5, 'Butter', 3.20, 60);
INSERT INTO Product VALUES (6, 'Yogurt', 1.80, 90);
INSERT INTO Product VALUES (7, 'Wool', 2.50, 40);
INSERT INTO Product VALUES (8, 'Honey', 6.00, 30);
INSERT INTO Product VALUES (9, 'Chicken meat', 4.50, 80);
INSERT INTO Product VALUES (10, 'Goat cheese', 4.80, 45);

INSERT INTO Customer VALUES (1, 'Anna Malá', 'anna.mala@gmail.com');
INSERT INTO Customer VALUES (2, 'Peter Veľký', 'peter.velky@gmail.com');
INSERT INTO Customer VALUES (3, 'Lucia Horváthová', 'lucia.h@gmail.com');
INSERT INTO Customer VALUES (4, 'Tomáš Bielik', 'tomas.b@gmail.com');
INSERT INTO Customer VALUES (5, 'Eva Černá', 'eva.c@gmail.com');
INSERT INTO Customer VALUES (6, 'Roman Varga', 'roman.v@gmail.com');
INSERT INTO Customer VALUES (7, 'Martina Kováčová', 'martina.k@gmail.com');
INSERT INTO Customer VALUES (8, 'Igor Sýkora', 'igor.s@gmail.com');
INSERT INTO Customer VALUES (9, 'Barbora Farkašová', 'barbora.f@gmail.com');
INSERT INTO Customer VALUES (10, 'Jozef Hruška', 'jozef.h@gmail.com');

INSERT INTO Product_Sale VALUES (1, 1, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 10, 15.00);
INSERT INTO Product_Sale VALUES (2, 2, TO_DATE('2024-04-02', 'YYYY-MM-DD'), 12, 24.00);
INSERT INTO Product_Sale VALUES (3, 3, TO_DATE('2024-04-03', 'YYYY-MM-DD'), 5, 20.00);
INSERT INTO Product_Sale VALUES (4, 4, TO_DATE('2024-04-04', 'YYYY-MM-DD'), 7, 38.50);
INSERT INTO Product_Sale VALUES (5, 5, TO_DATE('2024-04-05', 'YYYY-MM-DD'), 6, 19.20);
INSERT INTO Product_Sale VALUES (6, 6, TO_DATE('2024-04-06', 'YYYY-MM-DD'), 8, 14.40);
INSERT INTO Product_Sale VALUES (7, 7, TO_DATE('2024-04-07', 'YYYY-MM-DD'), 4, 10.00);
INSERT INTO Product_Sale VALUES (8, 8, TO_DATE('2024-04-08', 'YYYY-MM-DD'), 3, 18.00);
INSERT INTO Product_Sale VALUES (9, 9, TO_DATE('2024-04-09', 'YYYY-MM-DD'), 9, 40.50);
INSERT INTO Product_Sale VALUES (10, 10, TO_DATE('2024-04-10', 'YYYY-MM-DD'), 5, 24.00);

INSERT INTO Animal_Care VALUES (1, 1, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Vaccination');
INSERT INTO Animal_Care VALUES (2, 2, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Feeding');
INSERT INTO Animal_Care VALUES (3, 3, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Cleaning');
INSERT INTO Animal_Care VALUES (4, 4, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Health Check');
INSERT INTO Animal_Care VALUES (5, 5, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Feeding');
INSERT INTO Animal_Care VALUES (6, 6, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Vaccination');
INSERT INTO Animal_Care VALUES (7, 7, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Feeding');
INSERT INTO Animal_Care VALUES (8, 8, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Health Check');
INSERT INTO Animal_Care VALUES (9, 9, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Feeding');
INSERT INTO Animal_Care VALUES (10, 10, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 'Treatment');

INSERT INTO Feed VALUES (1, 'Hay', 500);
INSERT INTO Feed VALUES (2, 'Corn', 600);
INSERT INTO Feed VALUES (3, 'Grain', 450);
INSERT INTO Feed VALUES (4, 'Grass', 700);
INSERT INTO Feed VALUES (5, 'Barley', 400);
INSERT INTO Feed VALUES (6, 'Soy', 300);
INSERT INTO Feed VALUES (7, 'Wheat', 550);
INSERT INTO Feed VALUES (8, 'Mixed Feed', 500);
INSERT INTO Feed VALUES (9, 'Dry Grass', 350);
INSERT INTO Feed VALUES (10, 'Lucerne', 600);

INSERT INTO Animal_Feed VALUES (1, 1, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 5);
INSERT INTO Animal_Feed VALUES (2, 2, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 4);
INSERT INTO Animal_Feed VALUES (3, 3, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 3);
INSERT INTO Animal_Feed VALUES (4, 4, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 2);
INSERT INTO Animal_Feed VALUES (5, 5, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 6);
INSERT INTO Animal_Feed VALUES (6, 6, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 5);
INSERT INTO Animal_Feed VALUES (7, 7, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 3);
INSERT INTO Animal_Feed VALUES (8, 8, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 4);
INSERT INTO Animal_Feed VALUES (9, 9, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 2);
INSERT INTO Animal_Feed VALUES (10, 10, TO_DATE('2024-04-01', 'YYYY-MM-DD'), 5);

INSERT INTO Supplier VALUES (1, 'AgroSupplier SK', 'agro@skmail.com');
INSERT INTO Supplier VALUES (2, 'FarmTrade', 'farmtrade@sk.com');
INSERT INTO Supplier VALUES (3, 'GrainCorp', 'grain@corp.sk');
INSERT INTO Supplier VALUES (4, 'FeedWorld', 'info@feedworld.sk');
INSERT INTO Supplier VALUES (5, 'NatureFeed', 'nature@feed.sk');
INSERT INTO Supplier VALUES (6, 'AgroMarket', 'market@agro.sk');
INSERT INTO Supplier VALUES (7, 'FarmaPlus', 'plus@farma.sk');
INSERT INTO Supplier VALUES (8, 'CropConnect', 'contact@crop.sk');
INSERT INTO Supplier VALUES (9, 'AnimalPro', 'support@animalpro.sk');
INSERT INTO Supplier VALUES (10, 'SlovFeed', 'hello@slovfeed.sk');

INSERT INTO Feed_Supply VALUES (1, 1, TO_DATE('2024-03-25', 'YYYY-MM-DD'), 100);
INSERT INTO Feed_Supply VALUES (2, 2, TO_DATE('2024-03-25', 'YYYY-MM-DD'), 150);
INSERT INTO Feed_Supply VALUES (3, 3, TO_DATE('2024-03-26', 'YYYY-MM-DD'), 200);
INSERT INTO Feed_Supply VALUES (4, 4, TO_DATE('2024-03-26', 'YYYY-MM-DD'), 180);
INSERT INTO Feed_Supply VALUES (5, 5, TO_DATE('2024-03-27', 'YYYY-MM-DD'), 160);
INSERT INTO Feed_Supply VALUES (6, 6, TO_DATE('2024-03-27', 'YYYY-MM-DD'), 140);
INSERT INTO Feed_Supply VALUES (7, 7, TO_DATE('2024-03-28', 'YYYY-MM-DD'), 120);
INSERT INTO Feed_Supply VALUES (8, 8, TO_DATE('2024-03-28', 'YYYY-MM-DD'), 110);
INSERT INTO Feed_Supply VALUES (9, 9, TO_DATE('2024-03-29', 'YYYY-MM-DD'), 100);
INSERT INTO Feed_Supply VALUES (10, 10, TO_DATE('2024-03-29', 'YYYY-MM-DD'), 130);



-- POPIS: Tento pohľad zobrazuje priemerný vek zvierat pre každý druh. 
-- Používa agregačnú funkciu AVG() a zaokrúhľuje výsledky na dve desatinné miesta.
CREATE VIEW average_animal_age_by_species AS
SELECT 
    species,
    ROUND(AVG(age), 2) AS average_age
FROM 
    Animal
GROUP BY 
    species;
SELECT * FROM average_animal_age_by_species;



-- POPIS: Tento pohľad sumarizuje počet zvierat podľa ich zdravotného stavu.
-- Používa agregačnú funkciu COUNT() a GROUP BY pre zoskupenie podľa zdravotného stavu.
CREATE VIEW animal_health_summary AS
SELECT 
    health_status,
    COUNT(*) AS total_animals
FROM 
    Animal
GROUP BY 
    health_status;
SELECT * FROM animal_health_summary;



-- POPIS: Tento pohľad zobrazuje podrobnosti o predajoch produktov,
-- vrátane mena zákazníka, názvu produktu, množstva a celkovej ceny.
-- Spája tabuľky Product, Product_Sale a Customer.
CREATE VIEW product_sales_details AS
SELECT 
    c.name AS customer_name,
    p.name AS product_name,
    ps.quantity,
    ps.total_price,
    ps.sale_date
FROM 
    Product_Sale ps
JOIN 
    Product p ON ps.product_id = p.product_id
JOIN 
    Customer c ON ps.customer_id = c.customer_id;
SELECT * FROM product_sales_details;



-- POPIS: Tento pohľad zobrazuje kŕmenie zvierat vrátane názvu krmiva a množstva.
-- Spája tabuľky Animal_Feed a Feed.
CREATE VIEW animal_and_feed_usage AS
SELECT 
    af.animal_id,
    f.name AS feed_name,
    af.feed_date,
    af.amount
FROM 
    Animal_Feed af
JOIN 
    Feed f ON af.feed_id = f.feed_id;
SELECT * FROM animal_and_feed_usage;



-- POPIS: Tento pohľad zobrazuje všetky zvieratá a informáciu o ich ošetrovaní (aj keď žiadne nemajú).
-- Používa LEFT JOIN medzi Animal a Animal_care.
CREATE VIEW animals_with_care_info AS
SELECT 
    a.animal_id,
    a.species,
    a.health_status,
    ac.care_date,
    ac.care_type,
    ac.employee_id
FROM 
    Animal a
LEFT JOIN 
    Animal_care ac ON a.animal_id = ac.animal_id;
SELECT * FROM animals_with_care_info;



-- POPIS: Tento pohľad zobrazuje počet ošetrení zvierat podľa zamestnanca.
-- Používa LEFT JOIN a COUNT(*).
CREATE VIEW employee_care_count AS
SELECT 
    e.employee_id,
    e.name,
    COUNT(*) AS total_cares
FROM 
    Employee e
LEFT JOIN 
    Animal_care ac ON e.employee_id = ac.employee_id
GROUP BY 
    e.employee_id, e.name;
SELECT * FROM employee_care_count;



-- POPIS: Tento pohľad zobrazuje celkový počet predajov a tržby podľa mesiaca.
-- Používa TO_CHAR pre získanie roku a mesiaca.
CREATE VIEW monthly_sales_summary AS
SELECT 
    TO_CHAR(sale_date, 'YYYY-MM') AS sale_month,
    COUNT(*) AS total_sales,
    SUM(total_price) AS total_revenue
FROM 
    Product_Sale
GROUP BY 
    TO_CHAR(sale_date, 'YYYY-MM');
SELECT * FROM monthly_sales_summary;



-- POPIS: Tento pohľad zobrazuje identifikátory zvierat, ktoré boli buď nakŕmené, alebo ošetrené, ale nie oboje naraz.
-- Používa množinové operácie UNION, INTERSECT a MINUS na porovnanie údajov z tabuliek ANIMAL_FEED a ANIMAL_CARE.
-- Výsledkom sú zvieratá, ktoré sa nachádzajú len v jednej z tabuliek – teda boli buď len kŕmené, alebo len ošetrované.
CREATE VIEW Animals_Fed_Or_Cared_But_Not_Both AS
SELECT * FROM (
    (
        SELECT animal_id FROM ANIMAL_FEED
        UNION
        SELECT animal_id FROM ANIMAL_CARE
    )
    MINUS
    (
        SELECT animal_id FROM ANIMAL_FEED
        INTERSECT
        SELECT animal_id FROM ANIMAL_CARE
    )
);
SELECT * FROM Animals_Fed_Or_Cared_But_Not_Both;



-- POPIS: Tento pohľad zobrazuje zvieratá, ktoré boli kŕmené viac ako je priemerný počet kŕmení na zviera.
-- Používa vnorený selekt s agregáciou na výpočet priemeru a porovnanie s počtom kŕmení jednotlivých zvierat.
CREATE VIEW Animals_With_Above_Average_Feed AS
SELECT animal_id, COUNT(*) AS feed_count
FROM ANIMAL_FEED
GROUP BY animal_id
HAVING COUNT(*) > (
    SELECT AVG(feed_times) FROM (
        SELECT animal_id, COUNT(*) AS feed_times
        FROM ANIMAL_FEED
        GROUP BY animal_id
    )
);
SELECT * FROM Animals_With_Above_Average_Feed;



-- POPIS: Tento pohľad zobrazuje zvieratá, ktoré nikdy neboli ošetrené zamestnancom s ID = 1.
-- Používa vnorený selekt v klauzule WHERE s operátorom NOT IN.
CREATE VIEW Animals_Not_Cared_By_Employee_1 AS
SELECT animal_id
FROM ANIMAL
WHERE animal_id NOT IN (
    SELECT animal_id
    FROM ANIMAL_CARE
    WHERE employee_id = 1
);
SELECT * FROM Animals_Not_Cared_By_Employee_1;



CREATE SEQUENCE seq_primary_keys
START WITH 1
INCREMENT BY 1
NOCACHE
NOCYCLE;

CREATE OR REPLACE TRIGGER trg_farm_id
BEFORE INSERT ON Farm
FOR EACH ROW
BEGIN
  IF :NEW.farm_id IS NULL THEN
    SELECT seq_primary_keys.NEXTVAL INTO :NEW.farm_id FROM dual;
  END IF;
END;
/



CREATE OR REPLACE TRIGGER trg_check_animal_age
AFTER INSERT ON Animal
FOR EACH ROW
DECLARE
    ex_invalid_age EXCEPTION;
BEGIN
    IF :NEW.age < 0 THEN
        RAISE ex_invalid_age;
    END IF;
EXCEPTION
    WHEN ex_invalid_age THEN
        RAISE_APPLICATION_ERROR(-20001, 'Vek zvieraťa nemôže byť záporný.');
END;
/
