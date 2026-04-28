package xyz.teamgravity.jnidemo.core.extension

import timber.log.Timber

inline fun Any?.log() {
    Timber.d(this.toString())
}