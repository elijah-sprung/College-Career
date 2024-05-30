SET FOREIGN_KEY_CHECKS = 0;

INSERT INTO ANOMALY (ANOMALY_ID, ANOMALY_NAME, ANOMALY_DESCRIPT, ANOMALY_CHARACTER, ANOMALY_CONTAIN, ANOMALY_RISK, ANOMALY_DISRUPTION, ANOMALY_CREATE_ID) VALUES
#(1, 'Builder Bear', 'A small teddy bear, approximately 33 cm in height.', NULL, 'Keter', NULL, NULL, 2),
#(2, '1048-A', 'Similar to Builder Bear but made entirely of human ears.', NULL, 'Keter', NULL, NULL, NULL),
#(3, 'Sammy the Superfluous Serpent, by Sr. Supertainment', 'A non-venomous snake of an unidentified species. It is 1.1 meters in length.', NULL, 'Safe', 'Notice', 'VLAM', NULL),
#(4, 'Ruby Amulet', 'An ornate amulet approximately 15 centimeters in circumference made from white gold.', 1, 'Euclid', NULL, NULL, NULL);
#(12, 'Flute', 'A flute made from bone.', NULL, 'Euclid', NULL, NULL, NULL);
#(13, 'Old Greatcoat', 'A light brown, European military-style greatcoat from a period between the late 1500s to the early 1900s.', NULL, 'Euclid', NULL, NULL, NULL);
(14, 'Fleshy Growth', 'A tumorous, fleshy growth with a volume of roughly 60 m³ (or 2000 ft³).', NULL, 'Euclid', NULL, NULL, NULL);

INSERT INTO ANOMALY_HIST (ANOMALY_ID, ANOMALY_NAME, ANOMALY_DESCRIPT, ANOMALY_CHARACTER, ANOMALY_CONTAIN, ANOMALY_RISK, ANOMALY_DISRUPTION) VALUES
#(1, 'Builder Bear', 'A small teddy bear, approximately 33 cm in height.', NULL, 'Safe', NULL, NULL);
(12, 'Flute', 'A flute made from bone.', NULL, 'Safe', NULL, NULL);

INSERT INTO KNOWN_CHARACTERS (CHARACTER_ID, CHARACTER_NAME, CHARACTER_ANOMALY, CHARACTER_AUTHOR, LIFE_Status) VALUES
(1, 'Dr. Bright', 4, 1 , 'Immortal');

INSERT INTO AUTHOR (AUTHOR_ID, AUTHOR_NAME) VALUES
#(1, 'AdminBright'),
#(2, 'The Administrator');
(4, 'Sirens');

INSERT INTO ANOMALY_IN_SCP (SCP_DESIGNATION, ANOMALY_ID) VALUES
#(1048, 1),
#(4225, 3),
#(963, 4);
#(573, 12);
#(262, 13);
(002, 14);

INSERT INTO SCP (SCP_DESIGNATION, SCP_SERIES, ARTICLE_ID) VALUES
#(1048, 2, 1),
#(4225, 5, 2),
#(963, 1, 3);
#(573, 1, 18);
#(262, 1, 19);
(002, 1, 21);


INSERT INTO ARTICLE (ARTICLE_ID, ARTICLE_TITLE, ARTICLE_TYPE, AUTHOR_ID) VALUES
#(1, 'SCP-1048', 'SCP', 1),
#(2, 'SCP-4225', 'SCP', NULL),
#(3, 'SCP-963', 'SCP', NULL),
#(4, 'About the SCP Foundation', 'Guide', 2);
#(5, 'Groups of Interest', 'Guide', 4);
#(18, 'SCP-573', 'SCP', 1);
#(19, 'SCP-262', 'SCP', 2);
(21, 'SCP-002', 'SCP', 2);

#INSERT INTO GUIDE (GUIDE_TYPE, ARTICLE_ID, GUIDE_ID) VALUES
#('Writing Guides', 4, 1),
#('Writing Guides', 5, 2);

INSERT INTO GOI (GOI_NUM, GOI_NAME) VALUES
#(2, 'The Chaos Insurgency'),
#(3, 'The Three Moons Initiative'),
#(4, 'The Serpent\'s Hand'),
#(5, 'The Horizon Initiative'),
#(6, 'The Church of the Broken God'),
(7, 'Arcadia');

/*
INSERT INTO CONTAIN (CONTAIN_CLASS, CONTAIN_DESCRIPT) VALUES
('Safe', 'Anomalies that are easily and safely contained.'),
('Euclid', 'Anomalies that require more resources to contain completely or where containment isn\'t always reliable.'),
('Keter', 'Anomalies that are exceedingly difficult to contain consistently or reliably, with containment procedures often being extensive and complex.'),
('Thaumiel', 'Anomalies that the Foundation specifically uses to contain other SCPs.'),
('Neutralized', 'Anomalies that are no longer anomalous, either through having been intentionally or accidentally destroyed, or disabled.'),
('Apollyon', 'Anomalies that cannot be contained, are expected to breach containment imminently, or some other similar scenario.'),
('Archon', 'Anomalies that could theoretically be contained but are best left uncontained for some reason.');

INSERT INTO DISRUPTION (DISRUPTION_CLASS, DISRUPTION_DESCRIPT) VALUES
('Dark', 'So low as not to be a concern.'),
('Vlam', 'Localized to a small handful of people.'),
('Keneq', 'Roughly defined as a city.'),
('Ekhi', 'Roughly the size of a large metropolitan area to an entire country.'),
('Amida', 'The entire known world and possibly the entire universe.');

INSERT INTO RISK (RISK_CLASS, RISK_DESCRIPT) VALUES
('Notice', 'Nearly non-existant to mild.'),
('Caution', 'Mild to moderate.'),
('Warning', 'Moderate to significant.'),
('Danger', 'Significant to extreme.'),KNOWN_CHARACTERSKNOWN_CHARACTERSKNOWN_CHARACTERS
('Critical', 'Near instant and/or extremely severe.');
*/