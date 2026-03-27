package xyz.teamgravity.jnidemo.presentation.activity

import android.os.Bundle
import android.util.Log
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.Scaffold
import androidx.compose.ui.Modifier
import xyz.teamgravity.jnidemo.core.util.manager.MathManager
import xyz.teamgravity.jnidemo.presentation.theme.JNIDemoTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

        MathManager.sayHi()
        val manager = MathManager()
        Log.d("MathManager", manager.multiply(2.0, 2.5).toString())

        setContent {
            JNIDemoTheme {
                Scaffold(
                    modifier = Modifier.fillMaxSize()
                ) { padding ->

                }
            }
        }
    }
}