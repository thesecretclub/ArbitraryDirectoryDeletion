# From directory deletion to SYSTEM shell

Vulnerabilities enabling an unprivileged profile to make a service, run in SYSTEM security context or delete an arbitrary directory/file are not a rare occurrence.
They are mostly ignored by security researchers doing vulnerability hunting- as there is no established path to escalation of privilege using such a primitive.
By chance I have found such a path- using an unlikely quirk in the Windows Error Reporting Service.
The technical details are neither brilliant nor novel- but a writeup has been requested by several Twitter users.
