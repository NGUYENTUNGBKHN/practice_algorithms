
@echo off

@echo =======================
@echo [Run application]
@echo -----------------------
@echo .


if not exist "build\Debug\byte_pool.exe" (
    @echo [Error] Execute file not exist
) else (
    .\build\Debug\byte_pool.exe
)

@echo .
@echo -----------------------
@echo [End application]
@echo =======================
