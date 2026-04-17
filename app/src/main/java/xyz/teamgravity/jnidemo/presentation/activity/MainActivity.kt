package xyz.teamgravity.jnidemo.presentation.activity

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.Scaffold
import androidx.compose.ui.Modifier
import timber.log.Timber
import xyz.teamgravity.jnidemo.core.sample.OverloadSample
import xyz.teamgravity.jnidemo.core.sample.override.Child
import xyz.teamgravity.jnidemo.core.sample.override.Parent
import xyz.teamgravity.jnidemo.core.util.manager.LoanManager
import xyz.teamgravity.jnidemo.core.util.manager.MathManager
import xyz.teamgravity.jnidemo.presentation.theme.JNIDemoTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

        mathManager()
//        loanManager()
//        overloadSample()
//        overrideSample()

        setContent {
            JNIDemoTheme {
                Scaffold(
                    modifier = Modifier.fillMaxSize()
                ) { padding ->

                }
            }
        }
    }

    private fun mathManager() {
        MathManager.sayHi()
        val math = MathManager()
        Timber.d(math.multiply(2.0, 2.5).toString())
        Timber.d(math.isOdd(10).toString())
        Timber.d(math.damage(100).toString())
    }

    private fun loanManager() {
        val extraPay = LoanManager.calculateExtra(100.0)
        Timber.d(extraPay.toString())
    }

    private fun overloadSample() {
        val sample = OverloadSample()
        Timber.d(sample.add(1.0).toString())
        Timber.d(sample.add(1.0, 2.0).toString())
        Timber.d(sample.add(1.0, "5.5").toString())
        Timber.d(sample.add(1.0, 7.0, 3.0).toString())
        Timber.d(sample.minus(5.0).toString())
        Timber.d(sample.minus(5.0, 2.7).toString())
        Timber.d(sample.multiply(5.2).toString())
        Timber.d(sample.multiply(doubleArrayOf(2.3, 5.0, 5.2)).toList().toString())
        Timber.d(sample.multiply(2.3, "Ecoboost").toString())
        sample.multiply(sample, sample)
        sample.divide_me(5.0)
        sample.divide_me(5)
        sample.hello(5.0)
        OverloadSample.hello(5)
    }

    private fun overrideSample() {
        val parent = Parent()
        Timber.d(parent.mustang().toString())
        Timber.d(parent.malibu().toString())

        val child = Child()
        Timber.d(child.mustang().toString())
        Timber.d(child.malibu().toString())
    }
}