package xyz.teamgravity.jnidemo.presentation.activity

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.ui.Modifier
import xyz.teamgravity.jnidemo.core.extension.log
import xyz.teamgravity.jnidemo.core.sample.OverloadSample
import xyz.teamgravity.jnidemo.core.sample.override.Child
import xyz.teamgravity.jnidemo.core.sample.override.Parent
import xyz.teamgravity.jnidemo.core.util.manager.LoanManager
import xyz.teamgravity.jnidemo.core.util.manager.MathManager
import xyz.teamgravity.jnidemo.core.util.manager.TextManager
import xyz.teamgravity.jnidemo.data.model.PersonModel
import xyz.teamgravity.jnidemo.presentation.theme.JNIDemoTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

//        mathManager()
//        loanManager()
//        overloadSample()
//        overrideSample()
        textManager()

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
        math.multiply(2.0, 2.5).log()
        math.isOdd(10).log()
        math.damage(100).log()
        math.linearSpace(0.0, 5.0, 10).toList().log()
        math.sum(doubleArrayOf(1.0, 5.0, 6.0, 4.0, 5.0)).log()
        math.squareOf(doubleArrayOf(2.0, 7.0, 5.0)).toList().log()
        math.ones(5, 9).contentDeepToString().log()
        math.ones(arrayOf(doubleArrayOf())).contentDeepToString().log()
        math.max(arrayOf(doubleArrayOf(-1.0, 7.0), doubleArrayOf(-4.0, 1.5, -0.5))).log()
    }

    private fun loanManager() {
        LoanManager.calculateExtra(100.0).log()
    }

    private fun overloadSample() {
        val sample = OverloadSample()
        sample.add(1.0).log()
        sample.add(1.0, 2.0).log()
        sample.add(1.0, "5.5").log()
        sample.add(1.0, 7.0, 3.0).log()
        sample.minus(5.0).log()
        sample.minus(5.0, 2.7).log()
        sample.multiply(5.2).log()
        sample.multiply(doubleArrayOf(2.3, 5.0, 5.2)).toList().log()
        sample.multiply(2.3, "Ecoboost").log()
        sample.multiply(sample, sample)
        sample.divide_me(5.0)
        sample.divide_me(5)
        sample.hello(5.0)
        OverloadSample.hello(5)
    }

    private fun overrideSample() {
        val parent = Parent()
        parent.mustang().log()
        parent.malibu().log()

        val child = Child()
        child.mustang().log()
        child.malibu().log()
    }

    private fun textManager() {
        TextManager.hello().log()
        TextManager.print("10 000 push-ups.")
        TextManager.concat("Special", " One").log()

        val person = PersonModel("Raheem", 25, true, 777.777)
        TextManager.evaluatePerson(person)
        TextManager.divorcePerson(person)
        person.log()
    }
}