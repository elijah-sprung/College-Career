SELECT 
    a.ANOMALY_CONTAIN AS 'Anomaly Containment Levels With 3 or More Anomalies at its Level'
FROM
    ANOMALY a
        JOIN
    ANOMALY_IN_SCP ai ON a.ANOMALY_ID = ai.ANOMALY_ID
        JOIN
    SCP s ON ai.SCP_DESIGNATION = s.SCP_DESIGNATION
GROUP BY a.ANOMALY_CONTAIN
HAVING COUNT(a.ANOMALY_CONTAIN) > 2
ORDER BY a.ANOMALY_CONTAIN;