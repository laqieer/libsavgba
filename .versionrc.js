const version = {
    "filename": "VERSION",
    "type": "plain-text"
}

module.exports = {
    "types": [
        {"type": "feat", "section": "Features"},
        {"type": "fix", "section": "Bug Fixes"},
        {"type": "chore", "hidden": true},
        {"type": "docs", "hidden": true},
        {"type": "style", "hidden": true},
        {"type": "refactor", "hidden": true},
        {"type": "perf", "hidden": true},
        {"type": "test", "hidden": true},
        {"type": "revert", "hidden": true}
    ],
    "packageFiles": [version],
    "bumpFiles": [version]
}
