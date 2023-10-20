var addon = require('bindings')('addon.node')

//console.log('This should:', addon.toggle(2))

module.exports = {
    toggle: int => addon.toggle(int)
}
