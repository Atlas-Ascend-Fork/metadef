# DECLARE\_ERRORNO

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:08:32.252Z pushedAt=2026-10-15T03:48:04.672Z -->

Error code and description registration macro. This macro provides the following four error codes for users:

- **SUCCESS**: Success.
- **FAILED**: Failure.
- **PARAM\_INVALID**: Invalid parameter.
- **SCOPE\_NOT\_CHANGED**: The scope fusion rule is not matched, and the current pass is ignored.

The declaration is as follows:

```cpp
DECLARE_ERRORNO(0, 0, SUCCESS, 0);
DECLARE_ERRORNO(0xFF, 0xFF, FAILED, 0xFFFFFFFF);
DECLARE_ERRORNO_COMMON(PARAM_INVALID, 1);  // 50331649
DECLARE_ERRORNO(SYSID_FWK, 1, SCOPE_NOT_CHANGED, 201);
```

You can view the error code definitions in ***$\{INSTALL\_DIR\}*/compiler/include/register/register\_error\_codes.h**.

Replace *\$\{INSTALL\_DIR\}* with the file storage path after CANN software installation. For example, if you install the software as the **root** user, the default storage path is **/usr/local/Ascend/cann**.
