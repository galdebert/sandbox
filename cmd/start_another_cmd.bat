@echo:
@echo:
@echo close cmd when exe is done
start cmd /c py.exe -V

@echo:
@echo:
@echo leave cmd opened
start cmd /k py.exe -V

pause