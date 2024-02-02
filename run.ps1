Push-Location -Path "run"

Invoke-Expression "$PSScriptRoot\build\game\game.exe"

Pop-Location
